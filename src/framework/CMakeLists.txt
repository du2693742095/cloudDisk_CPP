set(target_name "framework")

file(GLOB SRCS "*.cpp")
file(GLOB HDRS "*.h")

add_library(${target_name} STATIC ${SRCS} ${HDRS})


# 将小写字符变为大写
string(TOUPPER ${target_name} target_name_upper)
target_compile_definitions(${target_name} 
    PRIVATE
        ${target_name_upper}_EXPORT
)
message(STATUS "${target_name_upper}_EXPORT")