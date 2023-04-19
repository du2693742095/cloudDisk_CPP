set(target_name "framework")

file(GLOB_RECURSE SRCS "*.cpp")
file(GLOB_RECURSE HDRS "*.h")

add_library(${target_name} STATIC ${SRCS} ${HDRS})

target_include_directories(${target_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${target_name} PUBLIC ${CMAKE_DL_LIBS})
target_compile_definitions(${target_name} PRIVATE -DUNICODE -D_UNICODE)