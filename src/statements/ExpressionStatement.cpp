//
// Created by leonw on 04.06.2026.
//


#include "../../include/statements/ExpressionStatement.hpp"

#include <algorithm>
#include <memory>

#include "Expression.hpp"

ExpressionStatement::ExpressionStatement(std::unique_ptr<Expression> expression) : m_expression(std::move(expression))
{

}

Expression* ExpressionStatement::getExpression() const
{
    return m_expression.get();
}

std::string ExpressionStatement::toString() const
{
    return m_expression->toString();
}

void ExpressionStatement::accept(Visitor& visitor)
{
    visitor.visit(*this);
}
