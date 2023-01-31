cmake_minimum_required(VERSION 3.24)
project(../../sirius)

set(CMAKE_CXX_STANDARD 11)
set(PROJECT_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../..)
include_directories(../../sirius/log)

MESSAGE(${PROJECT_ROOT_PATH})

add_subdirectory(${PROJECT_ROOT_PATH} sirius_src)

add_library(log_lib ../../sirius/log/log_event.cpp
        ../../sirius/log/log_event.h ../../sirius/log/log_level.cpp ../../sirius/util/lock/scoped_lock.hpp)

add_executable(log_test ../../test/log/test_lock.cpp)




