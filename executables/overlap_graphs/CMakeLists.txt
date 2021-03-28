cmake_minimum_required(VERSION 2.6)

add_executable(overlap_graphs
    overlap_graphs.cpp
)
target_link_libraries(overlap_graphs
    fasta_reader
    fasta_read
)

