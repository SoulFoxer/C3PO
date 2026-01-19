cmake_minimum_required(VERSION 3.26)
project(C3PO)

set(CMAKE_CXX_STANDARD 26)

add_executable(C3PO
        src/main.cpp
        src/Lexer.cpp
        src/Token.cpp
        src/Parser.cpp
        src/statements/VariableDeclarationStatement.cpp
        src/statements/Statement.cpp
        include/Lexer.hpp
        include/FileUtil.hpp
        include/Token.hpp
        include/Parser.hpp
        include/statements/VariableDeclarationStatement.hpp
        include/statements/Statement.hpp
        include/expressions/ExpressionStatement.hpp
        include/expressions/ExpressionStatement.hpp
        include/expressions/Expression.hpp
        include/expressions/LiteralExpression.hpp
        include/statements/ForLoopStatement.hpp
        include/statements/BlockStatement.hpp
)

target_include_directories(C3PO PUBLIC include)