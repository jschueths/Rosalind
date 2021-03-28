cmake_minimum_required(VERSION 3.16)

add_library(common args.hpp args.cpp)
target_include_directories(common PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(common Boost::program_options)
