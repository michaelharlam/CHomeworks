cmake_minimum_required(VERSION 3.29)
project(countingRhyme C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(countingRhyme
    list.c
    list.h
    main.c)
