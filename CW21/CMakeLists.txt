cmake_minimum_required(VERSION 3.29)
project(CW2 C)

set(CMAKE_C_STANDARD 11)

add_executable(CW2
        second/main.c
        second/fileReaderFileWriter.c
        second/fileReaderFileWriter.h
        second/queue.c
        second/queue.h)
