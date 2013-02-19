CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

ADD_LIBRARY(fastx
	read.h
	read.hpp
	fastx_reader.h
)

ADD_SUBDIRECTORY(fasta)

