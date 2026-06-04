//
// Created by leonw on 07.05.2026.
//

#include "../../include/expressions/FunctionCallExpression.hpp"
#include "../../include/visitor/Visitor.hpp"

FunctionCallExpression::FunctionCallExpression(std::string functionName)
    : m_functionName(std::move(functionName))
{
}

const std::string& FunctionCallExpression::getFunctionName() const {
    return m_functionName;
}

RuntimeValue FunctionCallExpression::accept(Visitor& visitor) {
    return visitor.visit(*this);
}

std::string FunctionCallExpression::toString() const {
    return m_functionName + "()";
}
