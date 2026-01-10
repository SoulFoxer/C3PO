//
// Created by leonw on 05.10.2025.
//

#include "../include/Parser.hpp"

#include <iostream>

#include "../include/statements/VariableDeclarationStatement.hpp"

std::vector<std::unique_ptr<Statement>> Parser::parse()
{
    std::vector<std::unique_ptr<Statement>> statements;
    std::cout << "started parsing..." << std::endl;

    auto nextToken = peek();

    if (nextToken.getType() == TokenType::VAR)
    {
        statements.push_back(parseVariableStatement());
    }

    std::cout << "finished parsing..." << std::endl;
    return statements;
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
    m_current++;
    return token;
}

Token Parser::currentToken()
{
    return m_tokens.at(m_current);
}

std::unique_ptr<Statement> Parser::parseVariableStatement()
{
    // Parse variable declaration statement: var myname = value;
    consume(TokenType::VAR);

    Token tokenIdentifier = consume(TokenType::IDENTIFIER);
    consume(TokenType::EQUALS);

    // Get the current token to determine if it's a number or identifier (string)
    Token valueToken = currentToken();

    std::variant<int, std::string> value;

    if (valueToken.getType() == TokenType::NUMBER)
    {
        consume(TokenType::NUMBER);
        value = std::get<int>(valueToken.getValue());
    }
    else if (valueToken.getType() == TokenType::IDENTIFIER)
    {
        // Assuming string literals are parsed as IDENTIFIER or add a STRING token type
        consume(TokenType::IDENTIFIER);
        value = std::get<std::string>(valueToken.getValue());
    }
    else
    {
        throw std::runtime_error("Expected NUMBER or STRING value");
    }

    consume(TokenType::SEMICOLON);

    std::string identifierString = std::get<std::string>(tokenIdentifier.getValue());
    std::cout << "Parsed variable declaration: " << identifierString << " = ";

    std::visit([](const auto& val)
    {
        std::cout << val;
    }, value);

    std::cout << ";" << std::endl;
    return  std::make_unique<VariableDeclarationStatement>(identifierString, value);
}
