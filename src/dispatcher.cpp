/*******************************************************************************
*    Veigar: Cross platform RPC library using shared memory.
*    ---------------------------------------------------------------------------
*    Copyright (C) 2023 winsoft666 <winsoft666@outlook.com>.
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/
#include "veigar/dispatcher.h"
#include "string_helper.h"
#include "log.h"
#include "veigar/veigar.h"

namespace veigar {
namespace detail {
using detail::Response;

Dispatcher::Dispatcher(Veigar* parent) noexcept :
    parent_(parent) {
}

bool Dispatcher::init() noexcept {
    if (init_) {
        return false;
    }

    for (size_t i = 0; i < 10; ++i) {
        workers_.emplace_back([this] {
            std::string exceptionMsg;
            for (;;) {
                std::shared_ptr<veigar_msgpack::object_handle> obj;

                {
                    std::unique_lock<std::mutex> lock(this->queueMutex_);
                    this->condition_.wait(lock, [this] { return this->stop_ || !this->objs_.empty(); });
                    if (this->stop_ && this->objs_.empty())
                        return;
                    obj = std::move(this->objs_.front());
                    this->objs_.pop();
                }

                if (!obj) {
                    continue;
                }

                auto msg = obj->get();

                std::string callerChannelName;
                Response resp = dispatch(msg, callerChannelName);
                if (callerChannelName.empty()) {
                    continue;
                }

                veigar_msgpack::sbuffer respBuf = resp.getData();
                if (respBuf.size() == 0) {
                    veigar::log("Veigar: the size of response data is zero.\n");
                    continue;
                }

                exceptionMsg.clear();
                if (!parent_->sendMessage(callerChannelName, (const uint8_t*)respBuf.data(), respBuf.size(), 100, exceptionMsg)) {
                    veigar::log("Veigar: send response to caller failed, caller: %s, exception: %s.\n",
                                callerChannelName.c_str(), exceptionMsg.c_str());
                }
            }
        });
    }

    init_ = true;

    return init_;
}

bool Dispatcher::isInit() const noexcept {
    return init_;
}

void Dispatcher::uninit() noexcept {
    if (!init_) {
        return;
    }
    {
        std::unique_lock<std::mutex> lock(queueMutex_);
        stop_ = true;
    }
    condition_.notify_all();
    for (std::thread& worker : workers_)
        worker.join();

    init_ = false;
}

void Dispatcher::pushCall(std::shared_ptr<veigar_msgpack::object_handle> result) noexcept {
    {
        std::unique_lock<std::mutex> lock(queueMutex_);

        // don't allow enqueueing after stopping the pool
        if (!stop_) {
            objs_.emplace(result);
        }
    }
    condition_.notify_one();
}

Response Dispatcher::dispatch(veigar_msgpack::object const& msg, std::string& callerChannelName) noexcept {
    // quickly check
    switch (msg.via.array.size) {
        case 5:
            return dispatchCall(msg, callerChannelName);
        default:
            return Response::MakeEmptyResponse();
    }
}

Response Dispatcher::dispatchCall(veigar_msgpack::object const& msg, std::string& callerChannelName) noexcept {
    CallMsg the_call;
    try {
        msg.convert(the_call);
    } catch (std::exception& e) {
        veigar::log("Veigar: parse response exception: %s.\n", e.what());
        return Response::MakeEmptyResponse();
    } catch (...) {
        veigar::log("Veigar: parse response exception.\n");
        return Response::MakeEmptyResponse();
    }

    // proper validation of protocol (and responding to it)
    auto&& type = std::get<0>(the_call);
    assert(type == 0);

    auto&& callId = std::get<1>(the_call);

    if (type != 0) {
        return Response::MakeResponseWithError(callId, std::string("invalid message flag"));
    }

    callerChannelName = std::get<2>(the_call);
    auto&& funcName = std::get<3>(the_call);
    auto&& args = std::get<4>(the_call);

    auto it_func = funcs_.find(funcName);

    if (it_func == end(funcs_)) {
        return Response::MakeResponseWithError(
            callId,
            StringHelper::StringPrintf("could not find function '%s' with argument count %d.", funcName.c_str(), args.via.array.size));
    }

    try {
        auto result = (it_func->second)(args);
        return Response::MakeResponseWithResult(callId, std::move(result));
    } catch (std::exception& e) {
        return Response::MakeResponseWithError(
            callId,
            StringHelper::StringPrintf("function '%s' (called with %d arg(s)) threw an exception. "
                                       "The exception contained this information: %s.",
                                       funcName.c_str(), args.via.array.size, e.what()));
    } catch (...) {
        return Response::MakeResponseWithError(
            callId,
            StringHelper::StringPrintf("function '%s' (called with %d arg(s)) threw an exception. "
                                       "The exception is not derived from std::exception. No further information available.",
                                       funcName.c_str(), args.via.array.size));
    }
}

bool Dispatcher::isFuncNameExist(std::string const& func) noexcept {
    auto pos = funcs_.find(func);
    if (pos != end(funcs_)) {
        return true;
    }
    return false;
}

}  // namespace detail
}  // namespace veigar