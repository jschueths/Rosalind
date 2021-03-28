cmake_minimum_required(VERSION 3.16)

add_library(common args.h args.cpp)
target_link_libraries(common Boost::program_options)
