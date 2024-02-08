cmake_minimum_required(VERSION 3.27)
project(mmn_23 C)

set(CMAKE_C_STANDARD 90)

add_executable(mmn_23 index.c
        error_utility.h
        error_utility.c
        utility.h
        utility.c
        constants.h
        globals.h
        index.h
        hash_utility.h
        hash_utility.c)
