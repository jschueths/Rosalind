cmake_minimum_required(VERSION 2.8)

project(rosalind CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

include_directories(include)
link_directories(${CMAKE_CURRENT_LIST_DIR}/lib)

add_compile_options(-Wall)

find_package(Boost REQUIRED)

add_subdirectory(include)
add_subdirectory(src)
# add_subdirectory(test)
add_subdirectory(executables)
