cmake_minimum_required(VERSION 3.16)

add_library(fastx
    src/read.hpp
    src/read.cpp
    src/fastx_reader.hpp
    src/fasta_read.hpp
    src/fasta_read.cpp
    src/fasta_reader.hpp
    src/fasta_reader.cpp
)

target_include_directories(fastx PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
