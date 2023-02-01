//
// Created by zhaobo on 2023/2/1.
// email 1173007724@qq.com
//

#ifndef SIRIUS_LOGGERMANAGER_H
#define SIRIUS_LOGGERMANAGER_H
#include "logger.h"
#include "../util/none_copy.hpp"
#include <map>

namespace sirius {
class LoggerManager : public NoneCopy {
public:

  LoggerManager * getInstance();

  Logger::ptr getLogger(const std::string &name);

  void init();

  Logger::ptr getRoot() const {return root_;}

  std::string toYamlString();

private:
  LoggerManager();

  std::map<std::string, Logger::ptr> logger_map_;

  Logger::ptr root_;
};
}


#endif //SIRIUS_LOGGERMANAGER_H
