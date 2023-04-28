cmake_minimum_required(VERSION 3.10)

#project(CloudDisk LANGUAGE C CXX)
project(CloudDisk)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "======== welcome to CloudDisk =======")

option(TEST "using for test (maybe it is gtest) " ON)


# 设置全局输出目录
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build, options are: Debug Release." FORCE)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(OUTPUT_DIR ${PROJECT_SOURCE_DIR}/output/bin_d)
else()
    set(OUTPUT_DIR ${PROJECT_SOURCE_DIR}/output/bin)
endif()
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

set(THIRDPARTY_DIR ${PROJECT_SOURCE_DIR}/src/3thparty)

add_subdirectory(src)

if(TEST)
    add_subdirectory(test)
endif()


# 拷贝配置文件到运行目录
set(CONFIG_DIR ${PROJECT_SOURCE_DIR}/conf)
if(EXISTS ${CONFIG_DIR})
    foreach(CONFIG_FILE ${CONFIG_DIR})
        #file(COPY ${CONFIG_FILE} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    endforeach()
else()
    message(SEND_ERROR "no config directory!")
endif()