/*
 * Copyright (c) winsoft666.
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */
#include "veigar/veigar.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <mutex>
#include <cstdlib>  //std::system
#include <inttypes.h>
#include "thread_group.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define IS_WINDOWS 1
#endif

#if IS_WINDOWS
bool IsWow64(HANDLE process, bool& result) {
    BOOL bIsWow64 = FALSE;

    typedef BOOL(WINAPI * LPFN_ISWOW64PROCESS)(HANDLE, PBOOL);
    LPFN_ISWOW64PROCESS fnIsWow64Process =
        (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");

    if (NULL == fnIsWow64Process) {
        return false;
    }

    if (!fnIsWow64Process(process, &bIsWow64)) {
        return false;
    }

    result = !!bIsWow64;
    return true;
}

bool IsWin64(HANDLE process) {
#if (defined _WIN64) || (defined WIN64)
    return true;
#else
    bool result = false;
    IsWow64(process, result);
    return result;
#endif
}

bool Is32BitProcess() {
    HANDLE process = GetCurrentProcess();
    if (!process)
        return false;

    bool wow64 = false;
    IsWow64(process, wow64);
    if (wow64)
        return true;

    BOOL win64 = IsWin64(process);
    return !win64;
}

#endif

std::string str1046 = R"(no4vvZcIIRoc3xz9ZkccRYo9XiliFGQqhnAk5zKz85ttbSI8IcOUGUx3OXagffEzSbuAO6W930KRSFBY0P6JlNPB0QyhhsFYl
vSHkwDnZOfLdWsS2zmDBa8It5Wcw9LWmKejilmpguZDO8vmtg4N1hUu2ayLJvoDAsQHiT5xL9qkF6KEznEba1ktT3grRNoGeZ
uESEHgdgxkViuLGXhkQX0wDVgGnMO9xsrWHtUu4WyXCPRXF7XGIvLaIRce1uyAKEb5SzeIg7A4fLXzufvdo8AholKI5nwQ0xh
1tnfOYtLLzvElGlkyJjHRoviSi1StkQKwKjHWIFYyVASDKzSTPWuqPFNXOigKsMlWkTerzSR6Ms1W9JBMxY8DB2XVMm7Nd1R7
vuoPEKJVwW7kIhCT6UQGG24s9GcQNayaM3BWg64TqGLhoYODkGgRJRwl0T1Iwg5opi8qyvKvW1B4oFL3Y1BbUSpsWsTXdt7OQ
qJqlTFrgKUsu5i5SYZOQezyU9YbrkcOvcrrEJFohV3yBoLRftslq7OvzgEhSFhTQRlXb0HwM30xoBgLdG44PLZ7N6pRqrAxmp
PK3WURadvOQKr4b6xPsLD5FA7jwRx8a8ZYIKece9DYgQ6V4YllSXiPytCmeNcvjnQK7pCLYiB6HUpcnT6QuH3FhU6APSOqN10
7krgZYdb1ucYRnLVz0PKLLpGGfw5RPDkhxkIKDO2bmFS4OwoSVip0ZWSKwYiM2xWgWFsCLE0y8ppC7kK3ixwdouss9Rvq9Y3W
I5uuTVNcilebnLkPwmlCIUclNETCVyxyXR0CUuRIHO0bXd6S0rxFSyej4TGo4UEecNxuTCsA6Ub9fgMwloKwYJKomiO83xmws
X7RHvEcSqriLCNS4etwZawJaQWiyVud9PZL4Ixxg7HuRBMwJtlYn7bx2Yx96RmItUU8DjtGZVUrbnTcLzeAGyqGhRjfzHTLwC
gVsPnzU5oqkOD3aNUCEs74gxRWQGR0iv9A17Fsnwgd44UBxOnAIlFXaNLZyn3reVSQJQnWpag8Wa)";

const uint32_t warnDelayMicroseconds = 6000000;  // 6000ms

std::string TimeToHuman(int64_t microseconds) {
    int64_t hour = microseconds / 3600000000;
    int64_t min = (microseconds % 3600000000) / 60000000;
    int64_t sec = (microseconds % 60000000) / 1000000;
    int64_t mill = (microseconds % 1000000) / 1000;
    int64_t micro = microseconds % 1000;

    std::string str;
    if (hour > 0)
        str += std::to_string(hour) + "h";
    if (min > 0)
        str += std::to_string(min) + "m";
    if (sec > 0)
        str += std::to_string(sec) + "s";
    if (mill > 0)
        str += std::to_string(mill) + "ms";
    if (micro > 0)
        str += std::to_string(micro) + "��s";
    return str;
}

std::vector<std::string> StringSplit(const std::string& src, const std::string& delimiter, bool includeEmptyStr) {
    std::vector<std::string> fields;
    typename std::string::size_type offset = 0;
    typename std::string::size_type pos = src.find(delimiter, 0);

    while (pos != std::string::npos) {
        std::string t = src.substr(offset, pos - offset);
        if ((t.length() > 0) || (t.length() == 0 && includeEmptyStr))
            fields.push_back(t);
        offset = pos + delimiter.length();
        pos = src.find(delimiter, offset);
    }

    const std::string t = src.substr(offset);
    if ((t.length() > 0) || (t.length() == 0 && includeEmptyStr))
        fields.push_back(t);
    return fields;
}

struct STATS {
    std::atomic<int64_t> error = 0;
    std::atomic<int64_t> success = 0;
    std::atomic<int64_t> totalUsed = 0;
};

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    printf("Veigar: Cross platform RPC library using shared memory.\n");
#if IS_WINDOWS
    printf("Version: %d.%d (%s)\n", veigar::VERSION_MAJOR, veigar::VERSION_MINOR, Is32BitProcess() ? "x86" : "x64");
#else
    printf("Version: %d.%d\n", veigar::VERSION_MAJOR, veigar::VERSION_MINOR);
#endif
    printf("Input 'quit' to exit the program.\n");
    printf("\n");

    std::string channelName;
    int outputRecv = 0;

    veigar::Veigar vg;
    vg.setTimeoutOfRWLock(200);

    while (true) {
        if (channelName.empty()) {
            std::cout << "Channel Name: ";
            std::cin >> channelName;

            if (channelName.empty()) {
                std::cout << "Channel name can not be empty.\n";
                continue;
            }

            if (channelName == "quit")
                break;

            if (!vg.init(channelName)) {
                printf("Init failed.\n");
                channelName.clear();
                continue;
            }

            std::cout << "Init success.\n";

            if (!vg.bind("echo", [&outputRecv](const std::string& msg, int id) {
                    if (outputRecv != 0) {
                        std::cout << "RECV:" << msg << std::endl;
                    }
                    return msg;
                    //return msg + "_" + std::to_string(id);
                })) {
                printf("Bind echo function failed.\n");
                continue;
            }

            std::cout << "Bind functions success.\n";
            std::cout << "Output received message(0/1): ";
            std::cin >> outputRecv;
            std::cout << "Armed.\n\n";
        }
        else {
            int callMethod = 0;
            int threadNum = 0;
            int callTimesEachThread = 0;
            int callTimeout = 0;
            std::string targetChannels;
            std::vector<std::string> targetChannelList;
            std::atomic<int64_t> respTotal = 0;
            std::vector<STATS*> statsList;

            std::cout << "Target channel names (Split by comma): ";
            std::cin >> targetChannels;

            if (targetChannels == "quit")
                break;

            targetChannelList = StringSplit(targetChannels, ",", false);
            if (targetChannelList.empty())
                continue;

            std::cout << "Timeout (ms):";
            std::cin >> callTimeout;

            std::cout << "Call method (0 = Sync, 1 = Async with promise, 2 = Async with callback): ";
            std::cin >> callMethod;

            std::cout << "The number of threads calling the target function: ";
            std::cin >> threadNum;

            std::cout << "The number of calls per thread: ";
            std::cin >> callTimesEachThread;

            auto fn = [&vg, &statsList, &respTotal, callTimeout, channelName, callMethod, callTimesEachThread](std::size_t threadId, std::string targetChannel) {
                STATS* stats = new STATS();
                statsList.push_back(stats);

                printf("[Thread %" PRId64 ", Target %s] Calling...\n", (int64_t)threadId, targetChannel.c_str());

                for (int i = 0; i < callTimesEachThread; i++) {
                    veigar::detail::TimeMeter tm;
                    veigar::CallResult ret;

                    if (callMethod == 0) {
                        ret = vg.syncCall(targetChannel, callTimeout, "echo", str1046, i);
                    }
                    else if (callMethod == 1) {  // Async with promise
                        std::shared_ptr<veigar::AsyncCallResult> acr = vg.asyncCall(targetChannel, callTimeout, "echo", str1046, i);
                        assert(acr);
                        if (acr) {
                            if (acr->second.valid()) {
                                auto waitResult = acr->second.wait_for(std::chrono::milliseconds(callTimeout));
                                if (waitResult == std::future_status::timeout) {
                                    ret.errCode = veigar::ErrorCode::TIMEOUT;
                                    ret.errorMessage = "Timeout";
                                }
                                else {
                                    ret = std::move(acr->second.get());
                                }
                            }
                            vg.releaseCall(acr->first);
                        }
                    }
                    else if (callMethod == 2) {  // Async with callback
                        auto startCallTS = std::chrono::high_resolution_clock::now();
                        vg.asyncCall(
                            [&respTotal, threadId, targetChannel, callTimesEachThread, startCallTS, i, stats](const veigar::CallResult& cr) {
                                int64_t used = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - startCallTS).count();
                                if (cr.isSuccess() && cr.obj.get().as<std::string>() == str1046) {
                                    stats->success++;
                                    if (used >= warnDelayMicroseconds) {
                                        printf("[Thread %" PRId64 ", Target %s] Warning: call %d take long time: %s >= %s\n",
                                               (int64_t)threadId, targetChannel.c_str(), i,
                                               TimeToHuman(used).c_str(), TimeToHuman(warnDelayMicroseconds).c_str());
                                    }
                                }
                                else {
                                    stats->error++;
                                    std::cout << cr.errorMessage << std::endl;
                                }

                                respTotal++;
                            },
                            targetChannel, callTimeout, "echo", str1046, i);
                    }

                    if (callMethod == 0 || callMethod == 1) {
                        int64_t used = tm.elapsed();
                        stats->totalUsed += used;

                        if (ret.isSuccess() && ret.obj.get().as<std::string>() == str1046) {
                            stats->success++;
                            if (used >= warnDelayMicroseconds) {
                                printf("[Thread %" PRId64 ", Target %s] Warning: call %d take long time: %s >= %s\n",
                                       (int64_t)threadId, targetChannel.c_str(), i, TimeToHuman(tm.elapsed()).c_str(), TimeToHuman(warnDelayMicroseconds).c_str());
                            }
                        }
                        else {
                            stats->error++;
                            std::cout << ret.errorMessage << std::endl;
                        }
                    }
                }

                if (callMethod == 0 || callMethod == 1) {
                    printf("[Thread %" PRId64 ", Target %s] Total %d, Success %" PRId64 ", Error %" PRId64 ", Used: %s, Average: %s/call, %" PRId64 "call/s.\n\n",
                           (int64_t)threadId, targetChannel.c_str(),
                           callTimesEachThread, stats->success.load(), stats->error.load(), TimeToHuman(stats->totalUsed.load()).c_str(),
                           TimeToHuman((int64_t)((double)stats->totalUsed.load() / (double)callTimesEachThread)).c_str(),
                           (int64_t)(1000000.0 / ((double)stats->totalUsed.load() / (double)callTimesEachThread)));

                    delete stats;
                }
            };

            veigar::detail::TimeMeter tmTotal;
            int64_t expectRspTotal = targetChannelList.size() * threadNum * callTimesEachThread;
            std::vector<std::shared_ptr<ThreadGroup>> threadGroups;

            for (auto targetChannel : targetChannelList) {
                auto tg = std::make_shared<ThreadGroup>();
                tg->createThreads(threadNum, targetChannel, fn);
                threadGroups.push_back(tg);
            }

            for (auto tg : threadGroups) {
                tg->joinAll();
            }

            if (callMethod == 2) {
                while (respTotal.load() < expectRspTotal)
                    std::this_thread::sleep_for(std::chrono::milliseconds(30));

                int64_t successTotal = 0, errorTotal = 0, totalUsed = 0;
                totalUsed = tmTotal.elapsed();
                for (STATS* s : statsList) {
                    successTotal += s->success.load();
                    errorTotal += s->error.load();
                    delete s;
                }
                statsList.clear();

                printf("Total %" PRId64 ", Success %" PRId64 ", Error %" PRId64 ", Used: %s, Average: %s/call, %" PRId64 "call/s.\n\n",
                       expectRspTotal, successTotal, errorTotal, TimeToHuman(totalUsed).c_str(),
                       TimeToHuman((int64_t)((double)totalUsed / (double)expectRspTotal)).c_str(),
                       (int64_t)(1000000.0 / ((double)totalUsed / (double)expectRspTotal)));
            }

            threadGroups.clear();
        }
    }

    if (vg.isInit()) {
        vg.uninit();
    }

    return 0;
}
