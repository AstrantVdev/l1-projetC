cmake_minimum_required(VERSION 3.24)
project(l1_projetC C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(l1_projetC
        main.c shape.h shape.c id.c id.h interface.c interface.h pixel.h area.h pixel.c area.c commands.c commands.h utils.c utils.h)
