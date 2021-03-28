cmake_minimum_required(VERSION 3.16)

add_executable(overlap_graphs src/overlap_graphs.main.cpp)
target_link_libraries(overlap_graphs fastx)

