//
// Created by zhaobo on 2023/2/5.
// email 1173007724@qq.com
//

#include "sirius/log/logger_manager.h"
#include "sirius/log/log_warp.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
  sirius::Logger::ptr logger =  sirius::LoggerManager::getInstance()->getLogger("root");
  sirius::LogWarp(logger, sirius::LogEvent::ptr(new sirius::LogEvent("asd", "asd", "asd",
                                                                     sirius::LogLevel::Level::DEBUG,
                                                                     123, 123, 123,
                                                                     123, 123))).getEventSS() << "hello word\n";
  return 0;
}