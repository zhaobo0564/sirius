//
// Created by zhaobo on 2023/2/1.
// email 1173007724@qq.com
//

#ifndef SIRIUS_LOG_WARP_H
#define SIRIUS_LOG_WARP_H
#include "log_event.h"

namespace sirius {

class LogWarp {
public:
  LogWarp(LogEvent::ptr log_event);

  ~LogWarp();

private:
  LogEvent::ptr log_event_;

};
}


#endif //SIRIUS_LOG_WARP_H
