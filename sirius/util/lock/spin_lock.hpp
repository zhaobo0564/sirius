//
// Created by zhaobo on 2023/1/8.
//
#ifndef SIRIUS_SPIN_LOCK_H
#define SIRIUS_SPIN_LOCK_H

#ifdef __APPLE__
#include <libkern/OSAtomic.h>
#elif __linux__
#include <pthread.h>
#endif
// maybe win32


class Spinlock {
private:    //private copy-ctor and assignment operator ensure the lock never gets copied, which might cause issues.
    Spinlock operator=(const Spinlock & asdf);
    Spinlock(const Spinlock & asdf);
#ifdef __APPLE__
    OSSpinLock m_lock;
public:
    Spinlock()
            : m_lock(0)
    {}
    void lock() {
      OSSpinLockLock(&m_lock);
    }
    bool try_lock() {
      return OSSpinLockTry(&m_lock);
    }
    void unlock() {
      OSSpinLockUnlock(&m_lock);
    }
#elif __linux__
    pthread_spinlock_t m_lock;
public:
    Spinlock() {
        pthread_spin_init(&m_lock, 0);
    }

    void lock() {
        pthread_spin_lock(&m_lock);
    }
    bool try_lock() {
        int ret = pthread_spin_trylock(&m_lock);
        return ret != 16;   //EBUSY == 16, lock is already taken
    }
    void unlock() {
        pthread_spin_unlock(&m_lock);
    }
    ~Spinlock() {
        pthread_spin_destroy(&m_lock);
    }
#endif
};
#endif//SIRIUS_SPIN_LOCK_H
