//
// Created by leonw on 25.09.2025.
//
#include "../include/Token.hpp"

std::string Token::typeToString(TokenType type)
{
    switch (type)
    {

    case TokenType::IDENTIFIER:     return "IDENTIFIER";
    case TokenType::NUMBER:         return "NUMBER";


    case TokenType::VAR:            return "VAR";
    case TokenType::PRINT:          return "PRINT";

    case TokenType::PLUS:           return "PLUS";
    case TokenType::MINUS:          return "MINUS";
    case TokenType::EQUALS:         return "EQUALS";

    case TokenType::SEMICOLON:      return "SEMICOLON";
    case TokenType::LEFT_PAREN:     return "LEFT_PAREN";
    case TokenType::RIGHT_PAREN:    return "RIGHT_PAREN";
    case TokenType::LEFT_BRACE:     return "LEFT_BRACE";
    case TokenType::RIGHT_BRACE:    return "RIGHT_BRACE";

    case TokenType::UNKNOWN:        return "UNKNOWN";
    case TokenType::END_OF_FILE:    return "EOF";

    default:                        return "UNDEFINED";
    }
}

std::ostream& operator<<(std::ostream& os, const Token& token)
{
    os << Token::typeToString(token.m_type) << "('" << token.m_value << "')";
    return os;
}