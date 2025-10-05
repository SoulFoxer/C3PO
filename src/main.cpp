#include <iostream>
#include "../include/Token.hpp"
#include "../include/Lexer.hpp"
#include "../include/FileUtil.hpp"
#include "../include/Parser.hpp"

int main()
{
    auto content = FileUtil::read_file("../src/source.txt");
    Lexer lexer(content);
    auto tokens = lexer.lex();

    std::cout << "=== Tokens ===" << std::endl;
    for (const auto& token : tokens)
    {
        std::cout << token << std::endl;
    }

    Parser parser(tokens)
    
    return 0;
}
