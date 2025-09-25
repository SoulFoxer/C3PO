#include <iostream>
#include <fstream>
#include <sstream>

#include "../include/Lexer.hpp"
#include "../include/FileUtil.hpp"
#include "../include/Token.hpp"

int main()
{
    auto content = FileUtil::read_file("../src/source.txt"); // or absolute path
    Lexer lexer(content);
    auto token_list = lexer.lex();

    for (auto& token : token_list)
    {
        std::cout << token.getValue() << std::endl;
    }
    return 0;
}
