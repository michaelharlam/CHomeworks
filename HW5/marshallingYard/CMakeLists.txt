cmake_minimum_required(VERSION 3.29)
project(marshallingYard C)

set(CMAKE_C_STANDARD 11)

add_executable(marshallingYard main.c ../stack/stack.c)

include_directories(../stack)

install(TARGETS marshallingYard DESTINATION bin)


install(FILES ../stack/*.h DESTINATION include)