//
// Created by zhaobo on 22-12-18.
//

#ifndef SIRIUS_LOG_EVENT_H
#define SIRIUS_LOG_EVENT_H
#include <iostream>
#include <string>
namespace sirius {
class LogEvent {
public:
  LogEvent();
private:
  const std::string file_name_;
  const std::string thead_name_;

  int32_t log_leven_;
  int32_t log_line_num_;
  uint32_t elapse_;   // 程序启动依赖的耗时
  int32_t thread_id_;
  int32_t coroutine_id_;  // 协程id
  uint64_t log_time_;

};
}


#endif // SIRIUS_LOG_EVENT_H
