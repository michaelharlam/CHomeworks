cmake_minimum_required(VERSION 3.29)
project(Graph C)

set(CMAKE_C_STANDARD 11)

add_executable(Graph
    main.c
        graph.c
        graph.h
        fileReader.c
        fileReader.h
        tests.c
        tests.h
        states.c
        list.c
        list.h
        hashTable.c
        hashTable.h
        states.h)
