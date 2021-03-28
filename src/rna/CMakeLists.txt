cmake_minimum_required(VERSION 2.8)

add_executable(rna_transcription rna_transcription.cpp)
target_link_libraries(rna_transcription common Boost::program_options)
