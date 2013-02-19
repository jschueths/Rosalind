CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

ADD_LIBRARY(fasta_read
	fasta_read.h
	fasta_read.hpp
)

ADD_LIBRARY(fasta_reader
	fasta_reader.h
	fasta_reader.hpp
)
TARGET_LINK_LIBRARIES(fasta_reader
	fast_reader
)

