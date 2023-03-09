cmake_minimum_required(VERSION 3.5)

project(Lab04 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lab04 main.cpp)

install(TARGETS Lab04
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
