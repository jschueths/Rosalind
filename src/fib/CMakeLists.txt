cmake_minimum_required(VERSION 3.16)

add_executable(fibonacci_rabbits fibonacci_rabbits.cpp)
target_link_libraries(fibonacci_rabbits Boost::program_options)
