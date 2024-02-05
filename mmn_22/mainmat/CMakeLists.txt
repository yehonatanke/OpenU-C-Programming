cmake_minimum_required(VERSION 3.27)
project(mmn_22___edit C)

set(CMAKE_C_STANDARD 90)

add_executable(mmn_22___edit mainmat.c
        mymat.c
        mymat.h
        constants.h
        mainmat.h
        process_input.c
        process_input.h
        utility.c
        error_utility.h
        error_utility.h
        error_utility.c
        message_utility.h
        globals.h
        tables_utility.c)
