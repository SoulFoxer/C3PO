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
    MULTIPLY,
    DIVIDE,
    EQUALS,

    TRUE_LITERAL,
    FALSE_LITERAL,

    IF,
    ELSE,

    SEMICOLON,
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    FUNCTION,
    UNKNOWN,
    END_OF_FILE,
    IMPORT,
};

class Token
{
public:
    using Value = std::variant<int, std::string>;

private:
    TokenType m_type;
    Value m_value;
    size_t m_lineNumber;
    size_t m_columnNumber;
    size_t m_length;

public:
    Token(TokenType type, std::string value, size_t lineNumber, size_t columnNumber, size_t m_length);

    Token(TokenType type, int value, size_t lineNumber, size_t columnNumber, size_t m_length);

    explicit Token(TokenType type, size_t lineNumber, size_t columnNumber, size_t m_length);


    [[nodiscard]] TokenType getType() const;
    const Value& getValue() const;

    bool isLiteral() const;

    bool isOperator() const;

    [[nodiscard]] size_t getLineNumber() const;

    [[nodiscard]] size_t getColumnNumber() const;
    [[nodiscard]] size_t getLength() const;

    static std::string typeToString(TokenType type);


    friend std::ostream& operator<<(std::ostream& os, const Token& token);
};

#endif //C3PO_TOKEN_HPP
