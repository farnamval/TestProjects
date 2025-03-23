cmake_minimum_required(VERSION 3.30.2)

project(my_program)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_program src/main.cpp src/transport_factory.cpp src/transport.cpp)
