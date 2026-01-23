//
// Created by leonw on 25.09.2025.
//

#ifndef C3PO_LEXER_HPP
#define C3PO_LEXER_HPP

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Token.hpp"

class Lexer
{
private:
    std::string m_source;
    size_t m_current = 0;
    std::map<std::string, TokenType> m_keywords;

    void advance();
    bool isAtEnd() const;
    char getCurrentChar() const;
    char peek(size_t offset = 1) const;
    bool isWhitespace(char c) const;

    void skipWhitespace();
    Token scanIdentifierOrKeyword();
    Token scanNumber();
    Token scanSymbol();

    Token scanString();

    static std::map<std::string, TokenType> buildKeywords();

public:
    explicit Lexer(std::string source) 
        : m_source(std::move(source))
        , m_keywords(buildKeywords())
    {
    }

    std::vector<Token> lex();
};


#endif //C3PO_LEXER_HPP
