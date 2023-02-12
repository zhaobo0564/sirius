//
// Created by zhaobo on 23-1-13.
//

#ifndef SIRIUS_LOG_FORMATTER_ITEM_H
#define SIRIUS_LOG_FORMATTER_ITEM_H

#include <memory>
#include "log_level.h"
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

class LogNameFormatItem: public LogFormatterItem {
public:
  LogNameFormatItem() {};

  void format(std::ostream& oss, LogEvent::ptr log_event) override {
   // oss << log_event->getLogger()->getName();
  }
};

class LineFormatItem : public LogFormatterItem {
public:
  LineFormatItem() {};

  void format(std::ostream& oss, LogEvent::ptr log_event) override {
    oss << log_event->getLogLineNum();
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
  LevelFormatItem() {};

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

class StringFormatItem : public LogFormatterItem {
public:
  StringFormatItem(const std::string msg = "") : msg_(msg) {

  };

  void format(std::ostream &oss, LogEvent::ptr) {
    oss << msg_;
  }

private:
  const std::string msg_;
};


// factory model
static LogFormatterItem::ptr getFormatterItem (const std::string name, const std::string var = "") {
  if (name == "m") {
    return LogFormatterItem::ptr(new MessageFormatItem());
  }

  if (name == "p") {
    return LogFormatterItem::ptr(new LevelFormatItem());
  }

  if (name == "r") {
    return LogFormatterItem::ptr(new LogTimeFormatItem());
  }

  if (name == "c") {
    return LogFormatterItem::ptr(new LogNameFormatItem());
  }

  if (name == "t") {
    return LogFormatterItem::ptr(new TheadIdFormatItem());
  }

  if (name == "n") {
    return LogFormatterItem::ptr(new StringFormatItem("\n"));
  }

  if (name == "d") {
    if (!var.empty()) {
      return LogFormatterItem::ptr(new LogTimeFormatItem(var));
    }
    return LogFormatterItem::ptr(new LogTimeFormatItem());
  }

  if (name == "f") {
    return LogFormatterItem::ptr(new FileNameFormatItem());
  }

  if (name == "l") {
    return LogFormatterItem::ptr(new LineFormatItem());
  }

  if (name == "T") {
    return LogFormatterItem::ptr(new StringFormatItem("\t"));
  }

  if (name == "F") {
    return LogFormatterItem::ptr(new FiberIdFormatItem());
  }

  if (name == "N") {
    return LogFormatterItem::ptr(new TheadNameFormatItem());
  }

  return LogFormatterItem::ptr(nullptr);
}
}

#endif // SIRIUS_LOG_FORMATTER_ITEM_H
