//
// Created by leonw on 25.09.2025.
//

#ifndef C3PO_TOKEN_HPP
#define C3PO_TOKEN_HPP
#include <string>
#include <ostream>

enum class TokenType
{

    IDENTIFIER,
    NUMBER,
    

    VAR,
    PRINT,
    

    PLUS,
    MINUS,
    EQUALS,

    SEMICOLON,
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,

    UNKNOWN,
    END_OF_FILE
};

class Token
{
private:
    TokenType m_type;
    std::string m_value;

public:
    Token(TokenType type, std::string value)
        : m_type(type), m_value(std::move(value))
    {
    }

    TokenType getType() const { return m_type; }
    const std::string& getValue() const { return m_value; }

    static std::string typeToString(TokenType type);

    friend std::ostream& operator<<(std::ostream& os, const Token& token);
};

#endif //C3PO_TOKEN_HPP
