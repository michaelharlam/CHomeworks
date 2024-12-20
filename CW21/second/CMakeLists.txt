cmake_minimum_required(VERSION 3.29)
project(CW21 C)

set(CMAKE_C_STANDARD 11)

add_executable(CW21
        main.c
        fileReaderFileWriter.c
        fileReaderFileWriter.h
        queue.c
        queue.h)
