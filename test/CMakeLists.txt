CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

ADD_EXECUTABLE(unittests
	main.cpp
	ReadTest.cpp
)
TARGET_LINK_LIBRARIES(unittests
	UnitTest++
    fastx
)
	
