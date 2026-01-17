//
// Created by leonw on 17.01.2026.
//

#ifndef C3PO_EXPRESSIONSTATEMENT_HPP
#define C3PO_EXPRESSIONSTATEMENT_HPP

#include <memory>

#include "statements/Statement.hpp"
#include "Expression.hpp"

class ExpressionStatement: public Statement
{
    std::unique_ptr<Expression> m_expression{};

public:
    ExpressionStatement(std::unique_ptr<Expression> expression)
        : m_expression(std::move(expression)) {}

    std::string toString() const override {
        return m_expression->toString() + ";";
    }

    const Expression& getExpression() const { return *m_expression; }
};


#endif //C3PO_EXPRESSIONSTATEMENT_HPP