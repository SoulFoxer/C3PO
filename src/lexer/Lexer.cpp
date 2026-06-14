//
// Created by leonw on 25.09.2025.
//
#include "../../include/lexer/Lexer.hpp"
#include "../../include/token/Token.hpp"

void Lexer::advance()
{
    if (getCurrentChar() == '\n')
    {
        m_startColumn = 1;
        m_startLine++;
    }else
    {
        m_startColumn++;
    }
    m_current++;
}

bool Lexer::isAtEnd() const
{
    return m_current >= m_source.length();
}

char Lexer::getCurrentChar() const
{
    if (isAtEnd())
    {
        return '\0';
    }
    return m_source[m_current];
}

char Lexer::peek(size_t offset) const
{
    if (m_current + offset >= m_source.length())
    {
        return '\0';
    }
    return m_source[m_current + offset];
}

bool Lexer::isWhitespace(char c)
{
    return c == ' ' || c == '\r' || c == '\t' || c == '\n';
}

std::map<std::string, TokenType> Lexer::buildKeywords()
{
    return {
        {"var", TokenType::VAR},
        {"print", TokenType::PRINT},
        {"for", TokenType::FOR_LOOP},
        {"true", TokenType::TRUE_LITERAL},
        {"false", TokenType::FALSE_LITERAL},
        {"if", TokenType::IF},
        {"else",TokenType::ELSE},
        {"function", TokenType::FUNCTION},
        {"import", TokenType::IMPORT}
    };
}

void Lexer::skipWhitespace()
{
    while (!isAtEnd() && isWhitespace(getCurrentChar()))
    {
        advance();
    }
}

Token Lexer::scanIdentifierOrKeyword()
{
    std::string name;

    size_t line = m_startLine;
    size_t column = m_startColumn;

    while (!isAtEnd() && std::isalnum(getCurrentChar()))
    {
        name += getCurrentChar();
        advance();
    }

    size_t length = m_startColumn - column;
    if (m_keywords.contains(name))
    {
        return Token(m_keywords.at(name), name, line, column, length);
    }

    return Token(TokenType::IDENTIFIER, name, line, column, length);
}

Token Lexer::scanNumber()
{
    std::string numberString;

    size_t line = m_startLine;
    size_t column = m_startColumn;

    while (!isAtEnd() && std::isdigit(getCurrentChar()))
    {
        numberString += getCurrentChar();
        advance();
    }

    int number = std::stoi(numberString);
    size_t length = m_startColumn - column;
    return Token(TokenType::NUMBER, number, line, column,length);
}

Token Lexer::scanSymbol()
{
    size_t line = m_startLine;
    size_t column = m_startColumn;

    char currentChar = getCurrentChar();
    advance();

    size_t tokenLength = 1;
    switch (currentChar)
    {
    case '+':
        return {TokenType::PLUS, "+", line, column, tokenLength};
    case '-':
        return {TokenType::MINUS, "-", line, column,tokenLength};
    case '*':
        return {TokenType::MULTIPLY, "*", line, column,tokenLength};
    case '/':
        return {TokenType::DIVIDE, "/", line, column,tokenLength};
    case ';':
        return {TokenType::SEMICOLON, ";", line, column,tokenLength};
    case '=':
        return {TokenType::EQUALS, "=", line, column,tokenLength};
    case '(':
        return {TokenType::LEFT_PAREN, "(", line, column,tokenLength};
    case ')':
        return {TokenType::RIGHT_PAREN, ")", line, column,tokenLength};
    case '{':
        return {TokenType::LEFT_BRACE, "{", line, column,tokenLength};
    case '}':
        return {TokenType::RIGHT_BRACE, "}", line, column,tokenLength};
    default:
        return {TokenType::UNKNOWN, std::string(tokenLength, currentChar), line, column,tokenLength};
    }
}

Token Lexer::scanString()
{
    size_t line = m_startLine;
    size_t column = m_startColumn;

    advance();

    std::string string;
    while (!isAtEnd() && getCurrentChar() != '"')
    {
        string += getCurrentChar();
        advance();
    }

    if (isAtEnd())
    {
        throw std::runtime_error("Unterminated string");
    }

    advance();
    size_t length = m_startColumn - column;
    return {TokenType::STRING, string, line, column, length};
}

std::vector<Token> Lexer::lex()
{
    std::vector<Token> tokens;

    while (!isAtEnd())
    {
        skipWhitespace();

        if (isAtEnd())
        {
            break;
        }

        char currentChar = getCurrentChar();

        if (std::isalpha(currentChar))
        {
            tokens.push_back(scanIdentifierOrKeyword());
        }
        else if (std::isdigit(currentChar))
        {
            tokens.push_back(scanNumber());
        }
        else if (currentChar == '"')
        {
            tokens.push_back(scanString());
        }
        else
        {
            tokens.push_back(scanSymbol());
        }
    }

    tokens.push_back(Token(TokenType::END_OF_FILE, "", m_startLine, m_startColumn,0));

    return tokens;
}
