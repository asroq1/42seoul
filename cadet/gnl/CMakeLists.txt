cmake_minimum_required(VERSION 3.21)
project(gnl)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(gnl
        get_next_line.c
        get_next_line.h
        get_next_line_utils.c
        main
        main.c
        test.txt)
