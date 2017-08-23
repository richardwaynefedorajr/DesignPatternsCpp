cmake_minimum_required(VERSION 3.2)
project(DesignPatternsCpp)
set(CMAKE_CXX_STANDARD 11)

#Bring the headers into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/main.cpp src/file.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(designPatterns ${SOURCES})
