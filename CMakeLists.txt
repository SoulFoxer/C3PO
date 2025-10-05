cmake_minimum_required(VERSION 4.0)
project(C3PO)

set(CMAKE_CXX_STANDARD 26)

add_executable(C3PO 
    src/main.cpp
    src/Lexer.cpp
    src/Token.cpp
    include/Lexer.hpp
    include/FileUtil.hpp
    include/Token.hpp
        src/Token.cpp
        src/Parser.cpp
        include/Parser.hpp
        src/statements/VariableDeclarationStatement.cpp
        include/statements/VariableDeclarationStatement.hpp
)
