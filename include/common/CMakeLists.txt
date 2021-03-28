cmake_minimum_required(VERSION 2.8)

add_library(common args.h args.cpp)
target_link_libraries(common Boost::program_options)
