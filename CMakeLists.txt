cmake_minimum_required(VERSION 3.16)

project(rosalind CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

link_directories(${CMAKE_CURRENT_LIST_DIR}/lib)

add_compile_options(-Wall -Wextra -Wpedantic)

find_package(Boost REQUIRED)

add_subdirectory(libs)
# add_subdirectory(test)
add_subdirectory(apps)
