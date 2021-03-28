cmake_minimum_required(VERSION 3.16)

add_executable(identifying_genomes
    main.cpp
)
target_link_libraries(identifying_genomes
    fastx
)


