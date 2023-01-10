//
// Created by zhaobo on 2023/1/10.
// email 1173007724@qq.com
//

#ifndef SIRIUS_SCOPED_LOCK_HPP
#define SIRIUS_SCOPED_LOCK_HPP

namespace sirius {

// 局部锁模版
template<class T>
class ScopedLock {
public:
  ScopedLock(T& mutex) : mutex_(mutex), is_lock_(false){
    lock();
  }

  ~ScopedLock() {
    unlock();
  }

  //加锁
  void lock() {
    if (!is_lock_) {
      mutex_.lock();
      is_lock_ = true;
    }
  }

  //解锁
  void unlock() {
    if (is_lock_) {
      mutex_.unlock();
      is_lock_ = false;
    }
  }

private:
  T &mutex_;
  bool is_lock_;
};
}

#endif //SIRIUS_SCOPED_LOCK_HPP
