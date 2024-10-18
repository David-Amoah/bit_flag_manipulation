cmake_minimum_required(VERSION 3.27)
project(bitFlags C)

set(CMAKE_C_STANDARD 99)

add_executable(main.c
        status.h
        bit_flags.h
        bit_flags.c
        main.c)
