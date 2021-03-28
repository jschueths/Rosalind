CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_EXECUTABLE(fibonacci_rabbits fibonacci_rabbits.cpp)
TARGET_LINK_LIBRARIES(fibonacci_rabbits Boost::program_options)
