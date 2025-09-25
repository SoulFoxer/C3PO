cmake_minimum_required(VERSION 4.0)
project(C3PO)

set(CMAKE_CXX_STANDARD 26)

add_executable(C3PO src/main.cpp
        src/Lexer.cpp
        include/Lexer.hpp
        include/FileUtil.hpp
        include/Token.hpp)
