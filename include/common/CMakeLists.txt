CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_LIBRARY(common
    args.h args.cpp
)
TARGET_LINK_LIBRARIES(common boost_program_options)
