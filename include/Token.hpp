//
// Created by leonw on 25.09.2025.
//

#ifndef C3PO_TOKEN_HPP
#define C3PO_TOKEN_HPP
#include <string>

enum class TokenType
{
    VAR,
    IDENTIFIER,
    NUMBER,
    PRINT,
    PLUS,
    MINUS,
    EQUALS,
    SEMICOLON
};

class Token
{
    TokenType m_type;
    std::string m_value;

public:
    explicit Token(TokenType type, std::string value)
        : m_type(type), m_value(std::move(value))
    {
    }

    [[nodiscard("wtf")]] TokenType type() const { return m_type; }
    [[nodiscard]] const std::string& getValue() const { return m_value; }
};


#endif //C3PO_TOKEN_HPP
