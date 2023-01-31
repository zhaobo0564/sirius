//
// Created by zhaobo on 23-1-13.
//

#ifndef SIRIUS_LOGGER_H
#define SIRIUS_LOGGER_H
#include <iostream>
#include <memory>
#include "log_event.h"
#include "log_appender.h"

namespace sirius {
class Logger : public std::enable_shared_from_this<Logger>{
public:
  typedef std::shared_ptr<Logger> ptr;

  Logger(const std::string name);

  void log(LogEvent::ptr log_event);

  void info(LogEvent::ptr log_event);

  void debug(LogEvent::ptr log_event);

  void warn(LogEvent::ptr log_event);

  void error(LogEvent::ptr log_event);

  void fatal(LogEvent::ptr log_event);

  void addAppender(LogAppender::ptr appender);

  void delAppender(LogAppender::ptr appender);

  void clearAppender();

  const std::string &getName() const;

private:
  const std::string name_;

  std::vector<LogAppender::ptr> log_appender_;

  Spinlock mutex_;



};
}



#endif // SIRIUS_LOGGER_H
