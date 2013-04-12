CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

ADD_LIBRARY(fasta_read
	fasta_read.h
    fasta_read.cpp
)
TARGET_LINK_LIBRARIES(fasta_read
    fastx
)
SET_TARGET_PROPERTIES(fasta_read PROPERTIES LINKER_LANGUAGE CXX)

ADD_LIBRARY(fasta_reader
	fasta_reader.h
    fasta_reader.cpp
)
TARGET_LINK_LIBRARIES(fasta_reader
    fasta_read
    fastx
)
SET_TARGET_PROPERTIES(fasta_reader PROPERTIES LINKER_LANGUAGE CXX)

