//
// Created by zhaobo on 22-12-18.
//

#ifndef SIRIUS_LOG_LEVEL_H
#define SIRIUS_LOG_LEVEL_H
#include <string>

namespace sirius {
class LogLevel {
public:
  enum Level {
    UNKNOW = 0,
    DEBUG = 1,
    INFO = 2,
    WARN = 3,
    ERROR = 4,
    FATAL = 5
  };

  LogLevel(const LogLevel &) = delete;

  LogLevel &operator=(const LogLevel &) = delete;

  static LogLevel &GetInstance();

  const std::string LogLevelToString(const LogLevel::Level level);

  const LogLevel::Level StringToLogLeven(const std::string level);

private:
  LogLevel(){};
};
}

#endif // SIRIUS_LOG_LEVEL_H
