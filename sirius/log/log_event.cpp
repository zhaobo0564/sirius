//
// Created by zhaobo on 22-12-18.
//

#include "log_event.h"

namespace sirius {

const std::string &LogEvent::getFileName() const {
  return file_name_;
}

const std::string &LogEvent::getTheadName() const {
  return thead_name_;
}

const std::string &LogEvent::getFiberName() const {
  return fiber_name_;
}

const LogLevel &LogEvent::getLogLevel() const {
  return log_level_;
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

const std::stringstream &LogEvent::getContent() const {
  return content_;
}
}