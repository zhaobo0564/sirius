//
// Created by zhaobo on 22-12-18.
//

#include "../../sirius/log/log_level.h"
#include <iostream>

typedef struct a {
    int x = 0;
} b;

int main() {
  std::string test;
  test += sirius::LogLevel::GetInstance().LogLevelToString(sirius::LogLevel::INFO);
  test += " ";
  test += sirius::LogLevel::GetInstance().LogLevelToString(sirius::LogLevel::DEBUG);
  test += " ";
  test += sirius::LogLevel::GetInstance().LogLevelToString(sirius::LogLevel::WARN);
  test += " ";
  test += sirius::LogLevel::GetInstance().LogLevelToString(sirius::LogLevel::ERROR);
  test += " ";
  test += sirius::LogLevel::GetInstance().LogLevelToString(sirius::LogLevel::FATAL);
  test += " ";
  test += sirius::LogLevel::GetInstance().LogLevelToString(sirius::LogLevel::UNKNOW);
  std::cout << test << "\n";
  sirius::LogLevel::Level tmp;
  tmp = sirius::LogLevel::GetInstance().StringToLogLeven("debug");
  std::cout << tmp << "\n";
  tmp = sirius::LogLevel::GetInstance().StringToLogLeven("DEBUG");
  std::cout << tmp << "\n";
  tmp = sirius::LogLevel::GetInstance().StringToLogLeven("info");
  std::cout << tmp << "\n";
  tmp = sirius::LogLevel::GetInstance().StringToLogLeven("INFO");
  std::cout << tmp << "\n";
  tmp = sirius::LogLevel::GetInstance().StringToLogLeven("Warn");
  std::cout << tmp << "\n";
  tmp = sirius::LogLevel::GetInstance().StringToLogLeven("WARN");
  std::cout << tmp << "\n";
  tmp = sirius::LogLevel::GetInstance().StringToLogLeven("error");
  std::cout << tmp << "\n";
  tmp = sirius::LogLevel::GetInstance().StringToLogLeven("ERROR");
  std::cout << tmp << "\n";
  tmp = sirius::LogLevel::GetInstance().StringToLogLeven("fatal");
  std::cout << tmp << "\n";
  tmp = sirius::LogLevel::GetInstance().StringToLogLeven("FATAL");
  std::cout << tmp << "\n";
  tmp = sirius::LogLevel::GetInstance().StringToLogLeven("fadasdtal");
  std::cout << tmp << "\n";
  tmp = sirius::LogLevel::GetInstance().StringToLogLeven("sdsaw123");
  std::cout << tmp << "\n";
}

