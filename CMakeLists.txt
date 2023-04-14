cmake_minimum_required(VERSION 3.24)
project(l1_projetC C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(l1_projetC
        fonctions.h
        main.c shape.h struct.h shape.c fonctions.c id.c id.h interface.c interface.h)
