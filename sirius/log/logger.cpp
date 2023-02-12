//
// Created by zhaobo on 23-1-13.
//

#include "logger.h"

namespace sirius {
  const std::string &Logger::getName() const {
    return name_;
  }

  void Logger::addAppender(LogAppender::ptr obs) {
    log_appender_.push_back(obs);
  }

  void Logger::delAppender(LogAppender::ptr appender) {
    auto it = std::find(log_appender_.begin(), log_appender_.end(), appender);
    if (it != log_appender_.end()) {
      log_appender_.erase(it);
    }
  }

  void Logger::clearAppender() {
    log_appender_.clear();
  }

  void Logger::log(LogEvent::ptr log_event) {
    for (auto it : log_appender_) {
      it->log(log_event);
    }
  }

  Logger::Logger(const std::string name): name_(name) {

  }

}