//
// Created by zhaobo on 23-1-13.
//

#ifndef SIRIUS_LOGGER_H
#define SIRIUS_LOGGER_H
#include <iostream>
#include <memory>

namespace sirius {
class Logger : public std::enable_shared_from_this<Logger>{
public:
  typedef std::shared_ptr<Logger> ptr;


};
}



#endif // SIRIUS_LOGGER_H
