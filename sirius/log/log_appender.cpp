//
// Created by zhaobo on 2023/1/22.
// email 1173007724@qq.com
//

#include "log_appender.h"


namespace sirius {
  void StdoutLogAppender::log(Logger::ptr logger, LogEvent::ptr log_event) {
    if (log_event->getLevel() >= level_) {
      ScopedLock<Spinlock> lock(mutex_);
      log_formatter_->format(std::cout, log_event);
    }
  }
}