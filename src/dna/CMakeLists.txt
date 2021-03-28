CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_EXECUTABLE(counting_nucleotides counting_nucleotides.cpp)
TARGET_LINK_LIBRARIES(counting_nucleotides Boost::program_options)


