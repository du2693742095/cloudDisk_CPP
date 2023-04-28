set(target_name "log")

file(GLOB_RECURSE SRCS "*.cpp")
file(GLOB_RECURSE HDRS "*.h")


add_library(${target_name} SHARED ${SRCS} ${HDRS})

set(log4cplus_DIR "${THIRDPARTY_DIR}/log4cplus/lib/cmake/log4cplus")
find_package(log4cplus REQUIRED)
if(log4cplus_FOUND)
	message("found log4cplus! ")
endif()

target_link_libraries(${target_name}
    PUBLIC
        log4cplus::log4cplusU
)

# 大小写转换
string(TOUPPER ${target_name} target_name_upper)
target_compile_definitions(${target_name} 
    PUBLIC
        ${target_name_upper}_EXPORT
)