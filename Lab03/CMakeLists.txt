cmake_minimum_required(VERSION 3.5)

project(Lab03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lab03 main.cpp)

install(TARGETS Lab03
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
