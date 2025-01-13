cmake_minimum_required(VERSION 3.29)
project(mergeSort C)

set(CMAKE_C_STANDARD 11)

add_library(list list.c)

add_executable(mergeSort main.c)
target_link_libraries(mergeSort list)

#
#include_directories(../list)
#
#install(TARGETS mergeSort DESTINATION bin)
#
#install(FILES ../list/*.h DESTINATION include)