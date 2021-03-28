cmake_minimum_required(VERSION 2.6)

add_library(fastx
    read.h
    read.cpp
    fastx_reader.h
)
set_target_properties(fastx PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(fasta)

