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
namespace sirius {

class Spinlock {
private:    //private copy-ctor and assignment operator ensure the lock never gets copied, which might cause issues.
  Spinlock operator=(const Spinlock &spinlock);

  Spinlock(const Spinlock &spinlock);

#ifdef __APPLE__
  OSSpinLock lock_;
public:
  Spinlock() : lock_(0) {
  }

  void lock() {
    OSSpinLockLock(&lock_);
  }

  bool try_lock() {
    return OSSpinLockTry(&lock_);
  }

  void unlock() {
    OSSpinLockUnlock(&lock_);
  }

#elif __linux__
    pthread_spinlock_t lock_;
public:
    Spinlock() {
        pthread_spin_init(&lock_, 0);
    }

    void lock() {
        pthread_spin_lock(&lock_);
    }

    bool try_lock() {
        int ret = pthread_spin_trylock(&lock_);
        return ret != 16;   //EBUSY == 16, lock is already taken
    }

    void unlock() {
        pthread_spin_unlock(&lock_);
    }

    ~Spinlock() {
        pthread_spin_destroy(&lock_);
    }
#endif
};
}
#endif//SIRIUS_SPIN_LOCK_H
