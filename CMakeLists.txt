cmake_minimum_required(VERSION 3.30)
project(Assignment_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Assignment_2 main.c
        my_library.c
        my_library.h
        dependency.c
        dependency.h
        ascii_art.c
        ascii_art.h
        display_Gantt.c
        display_Gantt.h
        tasks.c
        tasks.h
)
