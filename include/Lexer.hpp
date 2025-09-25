//
// Created by leonw on 25.09.2025.
//

#ifndef C3PO_LEXER_HPP
#define C3PO_LEXER_HPP

#include <iostream>
#include <string>
#include <vector>

class Token;

class Lexer
{
    std::string m_source;
    size_t m_current = 0;

public:
    explicit Lexer(std::string source) : m_source(std::move(source))
    {
    }

    void advance();
    bool isAtEnd() const;
    char getCurrentChar() const;
    std::vector<Token> lex();
};


#endif //C3PO_LEXER_HPP
