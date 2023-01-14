
INCLUDE_DIRECTORIES(
    log
    util
)

FILE(GLOB_RECURSE
    sirius_src
    log/*.cpp
    util/lock/*.cpp
)

add_library(sirius_lib ${sirius_src})

