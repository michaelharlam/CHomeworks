cmake_minimum_required(VERSION 3.29)
project(hashTable C)

set(CMAKE_C_STANDARD 11)

add_executable(hashTable
    main.c
        hashTable.c
        hashTable.h
        list.c
        list.h
        fileReader.c
        fileReader.h)
