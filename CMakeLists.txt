cmake_minimum_required(VERSION 3.30)
project(Assignment_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Assignment_2 main.c
        my_library.c
        my_library.h
        dependecy.c
        dependecy.h)
