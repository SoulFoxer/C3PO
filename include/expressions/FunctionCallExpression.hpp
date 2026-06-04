//
// Created by leonw on 07.05.2026.
//

#ifndef C3PO_FUNCTIONCALLEXPRESSION_HPP
#define C3PO_FUNCTIONCALLEXPRESSION_HPP
#include "Expression.hpp"

class FunctionCallExpression: public Expression
{
    std::string m_functionName;

public:
    explicit FunctionCallExpression(std::string functionName);

    [[nodiscard]] std::string toString() const override;
    RuntimeValue accept(Visitor& visitor) override;
    [[nodiscard]] const std::string& getFunctionName() const;
};

#endif //C3PO_FUNCTIONCALLEXPRESSION_HPP
