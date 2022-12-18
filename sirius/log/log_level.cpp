//
// Created by zhaobo on 22-12-18.
//

#include "log_level.h"
#include <algorithm>
#include <string>

namespace sirius {


LogLevel &LogLevel::GetInstance() {
  static LogLevel log_level;
  return log_level;
}

const std::string LogLevel::LogLevelToString(const LogLevel::Level level) {
#define ToString(name) \
  case LogLevel::name: \
    return #name;
  switch (level) {
    ToString(DEBUG);
    ToString(INFO);
    ToString(WARN);
    ToString(ERROR);
    ToString(FATAL);
  }
#undef ToString
  return "UNKNOW";
}

const LogLevel::Level LogLevel::StringToLogLeven(const std::string level) {
  std::string tmp = level;
  std::transform(tmp.begin(), tmp.end(),tmp.begin(), toupper);
#define StringTo(level) \
  if (tmp == #level) {  \
    return LogLevel::level;\
  }
  StringTo(DEBUG);
  StringTo(INFO);
  StringTo(WARN);
  StringTo(ERROR);
  StringTo(FATAL);
#undef StringTo
  return LogLevel::UNKNOW;
}

}