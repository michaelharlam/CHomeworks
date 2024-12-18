cmake_minimum_required(VERSION 3.29)
project(treeAVL2 C)

set(CMAKE_C_STANDARD 11)

add_executable(treeAVL2
    main.c
        treeAVL.c
        treeAVL.h
        tests.c
        tests.h
        dictionary.c
        dictionary.h)
