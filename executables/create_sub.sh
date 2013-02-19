mkdir $1
echo "CMAKE_MINIMUM_VERSION(VERSION 2.6)" >> ./$1/CMakeLists.txt
echo "add_subdirectory($1)" >> CMakeLists.txt

