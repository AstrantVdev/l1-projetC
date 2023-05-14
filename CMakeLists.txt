cmake_minimum_required(VERSION 3.24)
project(l1_projetC C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(l1_projetC
        shape.h shape.c id.c id.h interface.c interface.h pixel.c pixel.h area.h area.c commands.c commands.h utils.c utils.h main.c)
