cmake_minimum_required(VERSION 3.16)

add_library(fastx
    src/read.h
    src/read.cpp
    src/fastx_reader.h
    src/fasta_read.h
    src/fasta_read.cpp
    src/fasta_reader.h
    src/fasta_reader.cpp
)

target_include_directories(fastx PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
