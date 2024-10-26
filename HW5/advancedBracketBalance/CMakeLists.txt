cmake_minimum_required(VERSION 3.29)
project(advancedBracketBalance C)

set(CMAKE_C_STANDARD 11)

add_executable(advancedBracketBalance
    main.c
        stack.h
        stack.c)
