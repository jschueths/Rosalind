cmake_minimum_required(VERSION 3.16)

add_executable(counting_nucleotides counting_nucleotides.cpp)
target_link_libraries(counting_nucleotides Boost::program_options)


