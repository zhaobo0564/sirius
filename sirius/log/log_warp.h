//
// Created by zhaobo on 2023/2/6.
// email 1173007724@qq.com
//

#ifndef SIRIUS_LOG_WARP_H
#define SIRIUS_LOG_WARP_H
#include "logger.h"

namespace sirius {


class LogWarp {
public:
  LogWarp(Logger::ptr logger, LogEvent::ptr log_event);

  ~LogWarp();

  std::stringstream &getEventSS();

private:
  Logger::ptr logger_;
  LogEvent::ptr log_event_;
};
}


#endif //SIRIUS_LOG_WARP_H
