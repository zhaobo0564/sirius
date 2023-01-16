//
// Created by zhaobo on 23-1-13.
//

#ifndef SIRIUS_LOG_FORMATTER_ITEM_H
#define SIRIUS_LOG_FORMATTER_ITEM_H

#include <memory>
#include "logger.h"
#include "log_level.h"
#include "log_event.h"
#include <string>
#include <sstream>
#include <time.h>

namespace sirius {

class LogFormatterItem {
public:
  typedef std::shared_ptr<LogFormatterItem> ptr;

  virtual ~LogFormatterItem() {};

  virtual void format(std::ostream& oss, LogEvent::ptr log_event) = 0;

};

class MessageFormatItem : public LogFormatterItem {
public:
  MessageFormatItem() {};

  void format(std::ostream& oss, LogEvent::ptr log_event) override {
    oss << log_event->getContent();
  }
};

class FileNameFormatItem : public LogFormatterItem {
public:
  FileNameFormatItem() {};

  void format(std::ostream & oss, LogEvent::ptr log_event) override {
    oss << log_event->getFileName();
  }
};

class TheadNameFormatItem : public LogFormatterItem {
public:
  TheadNameFormatItem() {};

  void format(std::ostream &oss, LogEvent::ptr log_event) override {
    oss << log_event->getTheadName();
  }
};

class FiberNameFormatItem : public LogFormatterItem {
public:
  FiberNameFormatItem () {};

  void format(std::ostream &oss, LogEvent::ptr log_event) override {
    oss << log_event->getFileName();
  }
};

class LevelFormatItem : public LogFormatterItem {
public:
  LevelFormatItem();

  void format(std::ostream &oss, LogEvent::ptr log_event) override {
    oss << LogLevel::GetInstance().LogLevelToString(log_event->getLevel());
  }

};

class ElapseFormatItem : public LogFormatterItem {
public:
  ElapseFormatItem() {};

  void format(std::ostream &oss, LogEvent::ptr log_event) {
    oss << log_event->getFiberId();
  }
};

class TheadIdFormatItem : public LogFormatterItem {
public:
  TheadIdFormatItem() {};

  void format(std::ostream &oss, LogEvent::ptr log_event) {
    oss << log_event->getThreadId();
  }
};

class FiberIdFormatItem : public  LogFormatterItem {
public:
  FiberIdFormatItem() {};

  void format(std::ostream &oss, LogEvent::ptr log_event) {
    oss << log_event->getFiberId();
  }
};

class LogTimeFormatItem : public LogFormatterItem {
public:
  LogTimeFormatItem(const std::string &format = "%Y-%m-%d %H:%M:%S") : format_(format){
    if (format_.empty()) {
      format_ = "%Y-%m-%d %H:%M:%S";
    }
  };
  
  void format(std::ostream &oss, LogEvent::ptr log_event) {
    struct tm t;
    time_t log_time = log_event->getLogTime();
    localtime_r(&log_time, &t);
    char buf[40];
    strftime(buf, sizeof(buf), format_.c_str(), &t);
    oss << buf;
  }

private:
  std::string format_;
};
}

#endif // SIRIUS_LOG_FORMATTER_ITEM_H
