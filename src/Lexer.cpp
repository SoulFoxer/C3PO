//
// Created by leonw on 25.09.2025.
//
#include "../include/Lexer.hpp"
#include "../include/Token.hpp"

// ============================================================================
// Helper Methods
// ============================================================================

void Lexer::advance()
{
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

// ============================================================================
// Character Classification
// ============================================================================

bool Lexer::isWhitespace(char c) const
{
    return c == ' ' || c == '\r' || c == '\t' || c == '\n';
}

// ============================================================================
// Keyword Management
// ============================================================================

std::map<std::string, TokenType> Lexer::buildKeywords()
{
    return {
        {"var", TokenType::VAR},
        {"print", TokenType::PRINT}
    };
}

// ============================================================================
// Token Scanning Methods
// ============================================================================

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
    
    while (!isAtEnd() && std::isalnum(getCurrentChar()))
    {
        name += getCurrentChar();
        advance();
    }

    // Check if it's a keyword
    if (m_keywords.contains(name))
    {
        return Token(m_keywords.at(name), name);
    }
    
    return Token(TokenType::IDENTIFIER, name);
}

Token Lexer::scanNumber()
{
    std::string numberString;
    
    while (!isAtEnd() && std::isdigit(getCurrentChar()))
    {
        numberString += getCurrentChar();
        advance();
    }

    int number = std::stoi(numberString);
    
    return Token(TokenType::NUMBER, number);
}

Token Lexer::scanSymbol()
{
    char currentChar = getCurrentChar();
    advance();
    
    switch (currentChar)
    {
    case '+':
        return Token(TokenType::PLUS, "+");
    case '-':
        return Token(TokenType::MINUS, "-");
    case ';':
        return Token(TokenType::SEMICOLON, ";");
    case '=':
        return Token(TokenType::EQUALS, "=");
    case '(':
        return Token(TokenType::LEFT_PAREN, "(");
    case ')':
        return Token(TokenType::RIGHT_PAREN, ")");
    case '{':
        return Token(TokenType::LEFT_BRACE, "{");
    case '}':
        return Token(TokenType::RIGHT_BRACE, "}");
    default:
        // Handle unknown character
        return Token(TokenType::UNKNOWN, std::string(1, currentChar));
    }
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
        // Numbers
        else if (std::isdigit(currentChar))
        {
            tokens.push_back(scanNumber());
        }
        // Operators
        else
        {
            tokens.push_back(scanSymbol());
        }
    }

    tokens.push_back(Token(TokenType::END_OF_FILE, ""));
    
    return tokens;
}
