cmake_minimum_required(VERSION 3.24)
project(sirius)

set(CMAKE_CXX_STANDARD 14)

include_directories(sirius/log)

add_library(log_lib  sirius/log/log_event.cpp
        sirius/log/log_event.h sirius/log/log_level.cpp)

add_executable(log_test
        example/log/test_log_level.cpp)
target_link_libraries(log_test log_lib)


