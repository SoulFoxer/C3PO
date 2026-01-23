//
// Created by leonw on 25.09.2025.
//

#ifndef C3PO_TOKEN_HPP
#define C3PO_TOKEN_HPP

#include <string>
#include <ostream>
#include <variant>

enum class TokenType
{
    IDENTIFIER,
    NUMBER,
    STRING,

    VAR,
    PRINT,
    FOR_LOOP,

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
public:
    using Value = std::variant<int, std::string>;

private:
    TokenType m_type;
    Value m_value;

public:
    Token(TokenType type, std::string value)
        : m_type(type), m_value(std::move(value))
    {
    }

    Token(TokenType type, int value)
        : m_type(type), m_value(value)
    {
    }

    explicit Token(TokenType type)
        : m_type(type), m_value("")
    {
    }


    TokenType getType() const { return m_type; }
    const Value& getValue() const { return m_value; }

    bool isLiteral() const
    {
        return m_type == TokenType::NUMBER ||
               m_type == TokenType::STRING ||
               m_type == TokenType::IDENTIFIER;
    }

    bool isOperator() const
    {
        return m_type == TokenType::PLUS ||
               m_type == TokenType::MINUS ||
               m_type == TokenType::EQUALS;
    }

    static std::string typeToString(TokenType type);

    friend std::ostream& operator<<(std::ostream& os, const Token& token);
};

#endif //C3PO_TOKEN_HPP