CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(rosalind CXX)

INCLUDE_DIRECTORIES(include)
ADD_DEFINITIONS(-g -fsigned-char -Wall -W -Wshadow -Wpointer-arith -Wcast-qual -Winline -Werror)

ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(executables)

