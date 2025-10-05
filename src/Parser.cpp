//
// Created by leonw on 05.10.2025.
//

#include "../include/Parser.hpp"
#include "../include/statements/VariableDeclarationStatement.hpp"

void Parser::parse()
{
    // first only parse variableDeclarationStatement
}

Token Parser::peek()
{
    if (m_current + 1 >= m_tokens.size())
    {
        throw std::runtime_error("Unexpected end of file can not peek anymore");
    }
    return m_tokens.at(m_current + 1);
}

Token Parser::consume(TokenType type)
{
    Token token = currentToken();

    if (type != TokenType::END_OF_FILE && token.getType() != type)
    {
        throw std::runtime_error(
            "Expected token type " + Token::typeToString(type) + " but got " + Token::typeToString(token.getType()));
    }
    return token;
}

Token Parser::currentToken()
{
    return m_tokens.at(m_current);
}
