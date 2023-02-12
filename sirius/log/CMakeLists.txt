
set(log_src
    log_level.cpp
    log_event.cpp
    log_formatter.cpp
    log_appender.cpp
    logger.cpp
    log_warp.cpp
    logger_manager.cpp
    )

add_library(log_lib SHARED ${log_src})
