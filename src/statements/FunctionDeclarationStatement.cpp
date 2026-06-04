//
// Created by leonw on 15.03.2026.
//

#include "../include/statements/FunctionDeclarationStatement.hpp"
#include "../include/visitor/Visitor.hpp"

FunctionDeclarationStatement::FunctionDeclarationStatement(const std::string& functionName, const std::shared_ptr<BlockStatement>& block_statement) :
m_functionName(functionName), m_blockStatement(block_statement)
{

}

std::string FunctionDeclarationStatement::toString() const
{
    return "FunctionDeclarationStatement";
}

std::string FunctionDeclarationStatement::getFunctionName() const
{
    return m_functionName;
}

std::shared_ptr<BlockStatement> FunctionDeclarationStatement::getBlockStatement() const
{
    return m_blockStatement;
}

void FunctionDeclarationStatement::accept(Visitor& visitor)
{
    visitor.visit(*this);
}
