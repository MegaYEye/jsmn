cmake_minimum_required(VERSION 2.8)
project(jsmn_test)

include_directories(${CMAKE_SOURCE_DIR})
add_library(jsmn jsmn.c)
add_executable(main main.c)
add_executable(main2 main2.c)
target_link_libraries(main jsmn)

