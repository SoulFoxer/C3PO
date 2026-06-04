//
// Created by leonw on 04.06.2026.
//

#ifndef C3PO_EXPRESSIONSTATEMENT_HPP
#define C3PO_EXPRESSIONSTATEMENT_HPP
#include <memory>

#include "Statement.hpp"
#include "visitor/Visitor.hpp"
#include "../expressions/Expression.hpp"

class Expression;

class ExpressionStatement : public Statement {
private:
    std::unique_ptr<Expression> m_expression;
public:
    explicit ExpressionStatement(std::unique_ptr<Expression> expression);
    [[nodiscard]] Expression* getExpression() const;
    void accept(Visitor& visitor) override;
    [[nodiscard]] std::string toString() const override;
};

#endif //C3PO_EXPRESSIONSTATEMENT_HPP
