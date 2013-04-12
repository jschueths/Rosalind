CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

add_executable(identifying_genomes
	main.cpp
)
target_link_libraries(identifying_genomes
    fasta_reader
    fasta_read
)


