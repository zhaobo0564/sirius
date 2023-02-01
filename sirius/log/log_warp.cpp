//
// Created by zhaobo on 2023/2/1.
// email 1173007724@qq.com
//

#include "log_warp.h"

namespace sirius {
  LogWarp::LogWarp(LogEvent::ptr log_event) : log_event_(log_event) {}

  LogWarp::~LogWarp() {
    log_event_->getLogger()->log(log_event_);
  }
}