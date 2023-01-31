//
// Created by zhaobo on 23-1-13.
//

#include "log_formatter.h"
#include <iostream>

namespace sirius {

  LogFormatter::LogFormatter(const std::string &pattern) {
    if (!init()) {
      std::cerr << "LogFormatter init error !!!\n";
    }
  }

  bool LogFormatter::init() {
    int32_t pos = 0;
    std::string tmp = "";
    while (pos < pattern_.size()) {
      if (pattern_[pos] == '%') {
        if (!tmp.empty()) {
          formatters_.push_back(LogFormatterItem::ptr(new StringFormatItem(tmp)));
          tmp = "";
        }
        LogFormatterItem::ptr lfi;
        if (pos + 1 >= pattern_.size()) {
          return false;
        }
        pos++;
        if (pattern_[pos] == 'd') {
          std::string date_tmp = "";
          int left = 0, right = 0;
          while (pos < pattern_.size()) {
            if (pattern_[pos] == '{') {
              left++;
            } else if (pattern_[pos] == '}') {
              right++;
              break;
            } else {
              date_tmp += std::string(pattern_[pos], 1);
            }
            pos++;
          }
          if (left && left == right ) {
            lfi = getFormatterItem("d",date_tmp);
          } else {
            std::cerr << "log format parse error !!!\n";
            return false;
          }
        } else {
          lfi = getFormatterItem(std::string(pattern_[pos], 1));
        }
        if (lfi == nullptr) {
          std::cerr << "log format parse error !!!\n";
          return false;
        }
        formatters_.push_back(lfi);
      } else {
        tmp += std::string(pattern_[pos], 1);
      }
      pos++;
    }
    if (!tmp.empty()) {
      formatters_.push_back(LogFormatterItem::ptr(new StringFormatItem(tmp)));
    }
    return true;
  }

  std::string LogFormatter::format( LogEvent::ptr log_event) {
    std::stringstream buf;
    for (auto item : formatters_) {
      item->format(buf, log_event);
    }
    return buf.str();
  }

  std::ostream& LogFormatter::format(std::ostream &ofs, LogEvent::ptr log_event) {
    for (auto item: formatters_) {
      item->format(ofs, log_event);
    }
  }
}