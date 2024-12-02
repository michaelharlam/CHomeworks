cmake_minimum_required(VERSION 3.29)
project(treeAVL C)

set(CMAKE_C_STANDARD 11)

add_executable(treeAVL
        main.c
        treeAVL.c
        treeAVL.h)
