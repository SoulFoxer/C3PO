cmake_minimum_required(VERSION 3.26)
project(C3PO)

set(CMAKE_CXX_STANDARD 26)

add_executable(C3PO
        src/main.cpp
        src/lexer/Lexer.cpp
        src/parser/Parser.cpp
        src/statements/VariableDeclarationStatement.cpp
        src/statements/Statement.cpp
        src/visitor/Visitor.cpp
        src/statements/BlockStatement.cpp
        src/statements/FunctionDeclarationStatement.cpp
        src/statements/ForLoopStatement.cpp
        src/fileutil/FileUtil.cpp
        src/token/Token.cpp
        src/expressions/LiteralExpression.cpp
        include/expressions/BinaryExpression.hpp
        src/expressions/BinaryExpression.cpp
        include/statements/PrintStatement.hpp
        src/statements/PrintStatement.cpp
        include/expressions/VariableExpression.hpp
        src/expressions/VariableExpression.cpp
        src/visitor/ConcreteInterpreter.cpp
        src/statements/IfStatement.cpp
        src/expressions/FunctionCallExpression.cpp
        src/statements/ExpressionStatement.cpp
        src/statements/ImportStatement.cpp
)


target_include_directories(C3PO PUBLIC include/expressions)

target_include_directories(C3PO PUBLIC include/statements)

target_include_directories(C3PO PUBLIC include/visitor)
target_include_directories(C3PO PUBLIC include)

if(MINGW)
    target_link_options(C3PO PRIVATE -static-libgcc -static-libstdc++ -Wl,--allow-multiple-definition)
endif()