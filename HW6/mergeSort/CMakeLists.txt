cmake_minimum_required(VERSION 3.29)
project(mergeSort C)

set(CMAKE_C_STANDARD 11)

add_executable(mergeSort mergeSort.c ../list/list.с)

include_directories(../list)

install(TARGETS mergeSort DESTINATION bin)

install(FILES ../list/*.h DESTINATION include)