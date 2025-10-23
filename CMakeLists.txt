add_library(util)

include("${CMAKE_CURRENT_SOURCE_DIR}/config.cmake")

target_sources(util
        PUBLIC
        FILE_SET CXX_MODULES FILES
            util.cppm
)
