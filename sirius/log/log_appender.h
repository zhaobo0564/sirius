//
// Created by zhaobo on 2023/1/22.
// email 1173007724@qq.com
//

#ifndef SIRIUS_LOG_APPENDER_H
#define SIRIUS_LOG_APPENDER_H
#include "logger.h"
#include "../util/lock/spin_lock.hpp"
#include "../util/lock/scoped_lock.hpp"
#include "log_formatter.h"

namespace sirius {

class LogAppender{
  friend class Logger;
public:
  typedef std::shared_ptr<LogAppender> ptr;

  virtual void log(Logger::ptr logger, LogEvent::ptr log_event) = 0;

protected:
  LogLevel::Level level_ = LogLevel::DEBUG;
  Spinlock mutex_;
  LogFormatter::ptr log_formatter_;
};

class StdoutLogAppender : public LogAppender {
public:
  void log(Logger::ptr logger, LogEvent::ptr log_event);
};
}

#endif //SIRIUS_LOG_APPENDER_H
