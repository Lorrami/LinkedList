cmake_minimum_required(VERSION 3.21)
project(LinkedList)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        "main.cpp"
        "Unit.cpp"
        "LinkedList.cpp")

add_executable(LinkedList ${SOURCES})