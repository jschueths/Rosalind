CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

add_executable(overlap_graphs
    overlap_graphs.cpp
)
TARGET_LINK_LIBRARIES(overlap_graphs
    fasta_reader
    fasta_read
)

