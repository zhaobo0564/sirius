//
// Created by zhaobo on 2023/2/6.
// email 1173007724@qq.com
//

#include "log_warp.h"
namespace sirius {
  LogWarp::LogWarp(Logger::ptr logger, LogEvent::ptr log_event):logger_(logger), log_event_(log_event) {

  }

  LogWarp::~LogWarp() {
    logger_->log(log_event_);
  }

  std::stringstream & LogWarp::getEventSS() {
    return log_event_->getSS();
  }

}