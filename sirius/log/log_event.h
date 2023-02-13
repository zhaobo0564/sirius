//
// Created by zhaobo on 22-12-18.
//
#ifndef SIRIUS_LOG_EVENT_H
#define SIRIUS_LOG_EVENT_H
#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include "log_level.h"


namespace sirius {
class LogEvent {
public:
  typedef std::shared_ptr<LogEvent> ptr;

  LogEvent(const std::string file_name,
           const std::string thread_name,
           const std::string fiber_name,
           const LogLevel::Level level,
           int32_t log_line_num,
           uint32_t elapse,
           int32_t thread_id,
           int32_t fiber_id,
           uint64_t log_time
           );

  const std::string &getFileName() const;

  const std::string &getThreadName() const;

  const std::string &getFiberName() const;

  const LogLevel::Level &getLevel() const;

  int32_t getLogLineNum() const;

  uint32_t getElapse() const;

  int32_t getThreadId() const;

  int32_t getFiberId() const;

  uint64_t getLogTime() const;

  const std::string &getContent() const;

  std::stringstream &getSS();

  const std::string& getLogName();

  void setLogName(const std::string log_name);


private:
  const std::string file_name_;
  const std::string thread_name_;
  const std::string fiber_name_;
  std::string log_name_;

  LogLevel::Level level_;
  int32_t log_line_num_;
  uint32_t elapse_;   // 程序启动依赖的耗时
  int32_t thread_id_;
  int32_t fiber_id_;  // 协程id
  uint64_t log_time_;
  std::stringstream content_;
};
}


#endif // SIRIUS_LOG_EVENT_H
