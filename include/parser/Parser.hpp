//
// Created by leonw on 05.10.2025.
//

#ifndef C3PO_PARSER_HPP
#define C3PO_PARSER_HPP
#include <vector>

#include "../token/Token.hpp"
#include "../statements/BlockStatement.hpp"
#include "../statements/ForLoopStatement.hpp"
#include "../statements/ProgramStatement.hpp"
#include "../statements/Statement.hpp"
#include "../statements/FunctionDeclarationStatement.hpp"
#include "../expressions/Expression.hpp"

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
    std::unique_ptr<Statement> parsePrintStatement();
    std::unique_ptr<Statement> parseIfStatement();
    std::unique_ptr<FunctionDeclarationStatement> parseFunctionDeclarationStatement();
    std::unique_ptr<Statement> parseFunctionCallExpression();
    std::unique_ptr<ProgramStatement> parse();
    Token peek();
    Token consume(TokenType type);
    Token currentToken();

    std::unique_ptr<BlockStatement> parseBlockStatement();

    std::unique_ptr<Expression> parseExpression();
    std::unique_ptr<Expression> parsePrimary();
    std::unique_ptr<Expression> parseTerm();
    std::unique_ptr<Expression> parseFactor();
    std::unique_ptr<Expression> parseUnary();

};


#endif //C3PO_PARSER_HPP