//
// Created by zhaobo on 23-1-13.
//

#ifndef SIRIUS_LOG_FORMATTER_ITEM_H
#define SIRIUS_LOG_FORMATTER_ITEM_H

#include <memory>
#include "logger.h"
#include "log_level.h"
#include "log_event.h"

namespace sirius {

class LogFormatterItem {
public:
  typedef std::shared_ptr<LogFormatterItem> ptr;

  virtual ~LogFormatterItem() {};

  virtual void format(std::string& os,
                      LogLevel::Level level,
                      LogEvent::ptr log_event) = 0;

};

class MessageFormatItem : public LogFormatterItem {
public:
  MessageFormatItem() {};

  void format(std::string& os,
              LogLevel::Level level,
              LogEvent::ptr log_event) {

  }

};

}

#endif // SIRIUS_LOG_FORMATTER_ITEM_H
