set(target_name "test")

file(GLOB_RECURSE SRCS "*.cpp")
file(GLOB_RECURSE HDRS "*.h")

add_executable(${target_name} ${SRCS} ${HDRS})