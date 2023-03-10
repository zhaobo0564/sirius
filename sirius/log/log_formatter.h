//
// Created by zhaobo on 23-1-13.
//

#ifndef SIRIUS_LOG_FORMATTER_H
#define SIRIUS_LOG_FORMATTER_H
#include <memory>
#include "log_level.h"
#include "log_event.h"
#include "log_formatter_item.hpp"
#include <vector>

namespace sirius {
// 日志格式化类
class LogFormatter {
public:
  typedef std::shared_ptr<LogFormatter> ptr;

  /*
   * %m 消息
   * %p 日志级别
   * %r 累计毫秒数
   * %c 日志名称
   * %t 线程id
   * %n 换行
   * %d 时间
   * %f 文件名
   * %l 行号
   * %T 制表符
   * %F 协程id
   * %N 线程名称
   * 默认格式 "%d{%Y-%m-%d %H:%M:%S}%T%t%T%N%T%F%T[%p]%T[%c]%T%f:%l%T%m%n"
   * */
  LogFormatter(const std::string &pattern = "time[%d{%Y/%m/%d-%H:%M:%S}]%T%t%T%N%T%F%T[%p]%T[%c]%T%f:%l%T%m%n");

  bool init();

  std::string format(LogEvent::ptr log_event);

  std::ostream &format(std::ostream &ofs,
                       LogEvent::ptr log_event);

private:
  const std::string pattern_;
  std::vector<LogFormatterItem::ptr> formatters_;
};
}

#endif // SIRIUS_LOG_FORMATTER_H
