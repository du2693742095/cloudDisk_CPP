set(target_name "log")

file(GLOB_RECURSE SRCS "*.cpp")
file(GLOB_RECURSE HDRS "*.h")

set(LOG4CPP_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/log4cpp")
set(LOG4CPP_LIB_DIR "${SRC_DIR}/3thparty/log4cpp")

add_library(${target_name} SHARED ${SRCS} ${HDRS})

target_include_directories(${target_name}
    PUBLIC
        ${LOG4CPP_DIR}
)

target_link_libraries(${target_name}
    PUBLIC
        ${LOG4CPP_LIB_DIR}
)

# 将小写字符变为大写
string(TOUPPER ${target_name} target_name_upper)
target_compile_definitions(${target_name} 
    PRIVATE
        ${target_name_upper}_EXPORTS
)