cmake_minimum_required(VERSION 3.16)

add_library(fasta_read
    fasta_read.h
    fasta_read.cpp
)
target_link_libraries(fasta_read
    fastx
)

add_library(fasta_reader
    fasta_reader.h
    fasta_reader.cpp
)
target_link_libraries(fasta_reader
    fasta_read
    fastx
)
