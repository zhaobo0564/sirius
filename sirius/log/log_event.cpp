//
// Created by zhaobo on 22-12-18.
//

#include "log_event.h"

namespace sirius {

LogEvent::LogEvent(const std::string file_name,
                   const std::string thread_name,
                   const std::string fiber_name,
                   const LogLevel::Level level,
                   int32_t log_line_num,
                   uint32_t elapse,
                   int32_t thread_id,
                   int32_t fiber_id,
                   uint64_t log_time) : fiber_name_(fiber_name),
                   thread_name_(thread_name), level_(level), log_line_num_(log_line_num),
                   elapse_(elapse), thread_id_(thread_id), fiber_id_(fiber_id), log_time_(log_time){}

const std::string &LogEvent::getFileName() const {
  return file_name_;
}

const std::string &LogEvent::getThreadName() const {
  return thread_name_;
}

const std::string &LogEvent::getFiberName() const {
  return fiber_name_;
}

const LogLevel::Level &LogEvent::getLevel() const {
  return level_;
}

int32_t LogEvent::getLogLineNum() const {
  return log_line_num_;
}

uint32_t LogEvent::getElapse() const {
  return elapse_;
}

int32_t LogEvent::getThreadId() const {
  return thread_id_;
}

int32_t LogEvent::getFiberId() const {
  return fiber_id_;
}

uint64_t LogEvent::getLogTime() const {
  return log_time_;
}

const std::string &LogEvent::getContent() const {
  return content_.str();
}

std::stringstream &LogEvent::getSS() {
  return content_;
}

void LogEvent::setLogName(const std::string log_name) {
  log_name_ = log_name;
}

const std::string &LogEvent::getLogName() {
  return log_name_;
}

}