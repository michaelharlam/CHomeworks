cmake_minimum_required(VERSION 3.29)
project(modulesAndFiles C)

set(CMAKE_C_STANDARD 11)

add_executable(modulesAndFiles
    modulesAndFiles.c
        quickSort.h
        quickSort.c
        fileReader.c
        fileReader.h)
