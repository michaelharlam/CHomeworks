cmake_minimum_required(VERSION 3.29)
project(sortedList C)

set(CMAKE_C_STANDARD 11)

add_executable(sortedList
    main.c
        list.c
        list.h)
