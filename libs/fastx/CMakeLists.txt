cmake_minimum_required(VERSION 3.16)

add_library(fastx
    src/fastx/read.hpp
    src/fastx/read.cpp
    src/fastx/fastx_reader.hpp
    src/fastx/fasta_read.hpp
    src/fastx/fasta_read.cpp
    src/fastx/fasta_reader.hpp
    src/fastx/fasta_reader.cpp
)

target_include_directories(fastx PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
