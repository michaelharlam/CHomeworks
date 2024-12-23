cmake_minimum_required(VERSION 3.29)
project(parseTree C)

set(CMAKE_C_STANDARD 11)

add_executable(parseTree
    main.c
        parseTree.c
        parseTree.h
        expressionParser.h
        expressionParser.c)
