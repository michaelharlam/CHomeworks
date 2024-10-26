cmake_minimum_required(VERSION 3.29)
project(advancedBracketBalance C)

set(CMAKE_C_STANDARD 11)

add_executable(advancedBracketBalance main.c ../stack/stack.c)

include_directories(../stack)

install(TARGETS advancedBracketBalance DESTINATION bin)


install(FILES ../stack/*.h DESTINATION include)