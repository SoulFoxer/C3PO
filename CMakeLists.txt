cmake_minimum_required(VERSION 3.26) # 4.0 is not a valid standard version yet, 3.26+ is safe
project(C3PO)

set(CMAKE_CXX_STANDARD 26) # C++26 is experimental, make sure your compiler supports it (or use 23/20)

# 1. Create the executable FIRST
add_executable(C3PO
        src/main.cpp
        src/Lexer.cpp
        src/Token.cpp
        src/Parser.cpp
        src/statements/VariableDeclarationStatement.cpp
        src/statements/Statement.cpp
        # Headers are optional in add_executable but good for IDEs
        include/Lexer.hpp
        include/FileUtil.hpp
        include/Token.hpp
        include/Parser.hpp
        include/statements/VariableDeclarationStatement.hpp
        include/statements/Statement.hpp
)

# 2. THEN configure the include directories
target_include_directories(C3PO PUBLIC include)