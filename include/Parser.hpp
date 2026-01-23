//
// Created by leonw on 05.10.2025.
//

#ifndef C3PO_PARSER_HPP
#define C3PO_PARSER_HPP
#include <vector>

#include "Token.hpp"
#include "statements/BlockStatement.hpp"
#include "statements/ForLoopStatement.hpp"
#include "statements/ProgramStatement.hpp"
#include "statements/Statement.hpp"

class Parser
{
private:
    std::vector<Token> m_tokens;
    int m_current = 0;

public:
    explicit Parser(std::vector<Token> token) : m_tokens(std::move(token))
    {

    }

    std::unique_ptr<Statement> parseVariableStatement();
    std::unique_ptr<ProgramStatement> parse();
    Token peek();
    Token consume(TokenType type);
    Token currentToken();

    std::unique_ptr<BlockStatement> parseBlockStatement();

};


#endif //C3PO_PARSER_HPP