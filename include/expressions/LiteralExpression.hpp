//
// Created by leonw on 17.01.2026.
//

#ifndef C3PO_LITERALEXPRESSION_HPP
#define C3PO_LITERALEXPRESSION_HPP

#include <string>

#include "Expression.hpp"
#include "Token.hpp"
#include "variant"

class LiteralExpression: public Expression
{
private:
    std::variant<int, std::string> m_value{};
    TokenType m_type;

    std::string toString() const override
    {

    }
};

#endif //C3PO_LITERALEXPRESSION_HPP