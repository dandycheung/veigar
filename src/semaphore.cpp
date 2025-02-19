/*
 * Copyright (c) winsoft666.
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */
#include "semaphore.h"
#include "log.h"
#include <assert.h>
#include <limits>

namespace veigar {

bool Semaphore::IsExist(const std::string& name) {
#ifdef VEIGAR_OS_WINDOWS
    HANDLE h = OpenSemaphoreA(EVENT_MODIFY_STATE, FALSE, name.c_str());
    if (h) {
        CloseHandle(h);
    }
    return (h != NULL);
#else
    sem_t* sem = ::sem_open(name.c_str(), O_CREAT | O_EXCL);
    if (sem == SEM_FAILED) {
        return true;
    }
    ::sem_close(sem);
    return false;
#endif
}

bool Semaphore::open(const std::string& name, int value /*= 0*/, int maxValue /*= 2147483647*/) {
    assert(!name.empty());
    assert(!valid());
    if (name.empty())
        return false;

    close();

    sh_ = new SemaphoreHandle();
#ifdef VEIGAR_OS_WINDOWS
    HANDLE h = CreateSemaphoreA(NULL, value, maxValue, name.empty() ? NULL : name.c_str());
    if (h) {
        sh_->h_ = h;
    }
    else {
        veigar::log("Veigar: Error: CreateSemaphoreA failed, name: %s, gle: %d.\n", name.c_str(), GetLastError());
        delete sh_;
        sh_ = nullptr;
    }
#else
    sem_t* sem = ::sem_open(name.c_str(), O_CREAT, 0666, static_cast<unsigned int>(value));
    if (sem != SEM_FAILED) {
        sh_->named_ = sem;
    }
    else {
        int err = errno;
        veigar::log("Veigar: Error: sem_open failed, name: %s, errno: %d.\n", name.c_str(), err);
        delete sh_;
        sh_ = nullptr;
    }
#endif
    return valid();
}

void Semaphore::close() {
    if (valid()) {
#ifdef VEIGAR_OS_WINDOWS
        CloseHandle(sh_->h_);
        sh_->h_ = nullptr;
#else
        ::sem_close(sh_->named_);
        sh_->named_ = SEM_FAILED;
#endif

        delete sh_;
        sh_ = nullptr;
    }
}

bool Semaphore::valid() const {
    return !!sh_;
}

void Semaphore::wait() {
    if (valid()) {
#ifdef VEIGAR_OS_WINDOWS
        WaitForSingleObject(sh_->h_, INFINITE);
#else
        sem_wait(sh_->named_);
#endif
    }
}

bool Semaphore::wait(const int64_t& ms) {
    if (!valid()) {
        return false;
    }

#ifdef VEIGAR_OS_WINDOWS
    DWORD result = WaitForSingleObject(sh_->h_, ms >= 0 ? (DWORD)ms : INFINITE);
    return (result == WAIT_OBJECT_0);
#else
    if (ms >= 0) {
        timespec ts;

        timespec ts_now;
        clock_gettime(CLOCK_REALTIME, &ts_now);

        ts.tv_sec = ts_now.tv_sec;
        ts.tv_nsec = ts_now.tv_nsec;

        ts.tv_sec += (ms / 1000);
        ts.tv_nsec += ((ms % 1000) * 1000000);

        return (sem_timedwait(sh_->named_, &ts) == 0);
    }

    return (sem_wait(sh_->named_) == 0);
#endif
}

void Semaphore::release() {
    if (valid()) {
#ifdef VEIGAR_OS_WINDOWS
        ReleaseSemaphore(sh_->h_, 1, NULL);
#else
        sem_post(sh_->named_);
#endif
    }
}

}  // namespace veigar