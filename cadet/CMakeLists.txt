cmake_minimum_required(VERSION 3.21)
project(cadet C)

set(CMAKE_C_STANDARD 11)

include_directories(get_next_line)

add_executable(cadet
        get_next_line/get_next_line.c
        get_next_line/get_next_line.h
        get_next_line/get_next_line_utils.c
        get_next_line/main.c)
