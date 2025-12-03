add_library(util)

include("${CMAKE_CURRENT_SOURCE_DIR}/config.cmake")

find_package(CUDAToolkit)

target_sources(util
        PUBLIC
        FILE_SET CXX_MODULES FILES
            util.cppm
)

if(STATISTICS AND CUDAToolkit_FOUND)
    add_subdirectory(statistics)
    target_link_libraries(util PUBLIC statistics)
endif()