//
// Created by zhaobo on 2023/2/1.
// email 1173007724@qq.com
//

#include "logger_manager.h"
#include "log_appender.h"

namespace sirius {
  Logger::ptr LoggerManager::getLogger(const std::string &name) {
    auto it = logger_map_.find(name);
    if (it != logger_map_.end()) {
      return it->second;
    }

    Logger::ptr logger(new Logger(name));
    logger_map_[name] = logger;
    return logger;
  }

  LoggerManager * LoggerManager::getInstance() {
    static LoggerManager logger_manager;
    return &logger_manager;
  }

  LoggerManager::LoggerManager() : root_(new Logger("root")) {
    root_->addAppender(LogAppender::ptr(new StdoutLogAppender));
    logger_map_["root"] = root_;
  }
}