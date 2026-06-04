//
// Created by Leon on 20.04.2026.
//

#include <iostream>
#include <stdexcept>
#include "../../include/visitor/ConcreteInterpreter.hpp"

#include "../../include/statements/ExpressionStatement.hpp"
#include "FunctionCallExpression.hpp"
#include "IfStatement.hpp"
#include "../../include/statements/ProgramStatement.hpp"
#include "../../include/statements/VariableDeclarationStatement.hpp"
#include "../../include/statements/ForLoopStatement.hpp"
#include "../../include/statements/BlockStatement.hpp"
#include "../../include/statements/FunctionDeclarationStatement.hpp"
#include "../../include/statements/PrintStatement.hpp"
#include "../../include/expressions/LiteralExpression.hpp"
#include "../../include/expressions/BinaryExpression.hpp"
#include "../../include/expressions/VariableExpression.hpp"

ConcreteInterpreter::ConcreteInterpreter()
{
    m_environmentStack.push_back({});
}

void ConcreteInterpreter::visit(ProgramStatement& stmt)
{
    for (const auto& statement : stmt.getStatements())
    {
        statement->accept(*this);
    }
}

void ConcreteInterpreter::visit(VariableDeclarationStatement& stmt)
{
    auto& expression = stmt.getExpression();
    if (expression)
    {
        RuntimeValue value = expression->accept(*this);
        m_environmentStack.back()[stmt.getVariableName()] = value;
    }
    else
    {
        std::cout << "Error: expression is null" << std::endl;
    }
}

void ConcreteInterpreter::visit(ForLoopStatement& stmt)
{
    std::cout << "Executing for loop..." << std::endl;
    stmt.getBody()->accept(*this);
}

void ConcreteInterpreter::visit(IfStatement& stmt)
{
    RuntimeValue conditionValue = stmt.getCondition().accept(*this);
    bool isTrue = false;

    std::visit([&isTrue](auto&& val)
    {
        using T = std::decay_t<decltype(val)>;
        if constexpr (std::is_same_v<T, bool>) {
            isTrue = val;
        } else {
            throw std::runtime_error("Laufzeitfehler: Die Bedingung in einem 'if' muss ein boolean sein.");
        }
    }, conditionValue);

    if (isTrue)
    {
        stmt.getThenBranch().accept(*this);
    }else if (stmt.hasElseBranch())
    {
        stmt.getElseBranch().accept(*this);
    }
}

void ConcreteInterpreter::visit(ExpressionStatement& stmt)
{
    stmt.getExpression()->accept(*this);
}

void ConcreteInterpreter::visit(BlockStatement& block)
{
    // creates new environment (scope) on the stack
    m_environmentStack.push_back({});
    for (const auto& statement : block.getStatements())
    {
        statement->accept(*this);
    }
    // deletes the new environment (scope) from the stack
    m_environmentStack.pop_back();
}

RuntimeValue ConcreteInterpreter::visit(LiteralExpression& stmt)
{
    return stmt.getValue();
}

RuntimeValue ConcreteInterpreter::visit(BinaryExpression& stmt)
{
    auto op = stmt.getOperator();
    auto left = stmt.getLeft()->accept(*this);
    auto right = stmt.getRight()->accept(*this);

    return std::visit([op]<typename L, typename R>(L&& l, R&& r) -> RuntimeValue
    {
        using TYPE_LEFT = std::decay_t<L>;
        using TYPE_RIGHT = std::decay_t<R>;

        if constexpr (std::is_same_v<TYPE_LEFT, int> && std::is_same_v<TYPE_RIGHT, int>)
        {
            switch (op)
            {
            case TokenType::PLUS: return l + r;
            case TokenType::MINUS: return l - r;
            case TokenType::MULTIPLY: return l * r;
            case TokenType::DIVIDE:
                if (r == 0) throw std::runtime_error("Laufzeitfehler: Division durch Null!");
                return l / r;
            default:
                throw std::runtime_error("Laufzeitfehler: Unbekannter Operator für Zahlen.");
            }
        }
        else if constexpr (std::is_same_v<TYPE_LEFT, std::string> && std::is_same_v<TYPE_RIGHT, std::string>)
        {
            switch (op)
            {
            case TokenType::PLUS: return l + r;
            default:
                throw std::runtime_error("Laufzeitfehler: Strings können nur addiert werden.");
            }
        }
        else
        {
            throw std::runtime_error("Laufzeitfehler: Typen stimmen nicht überein (z.B. Zahl + String).");
        }
    }, left, right);
}

void ConcreteInterpreter::visit(FunctionDeclarationStatement& stmt)
{
    m_functions.insert({stmt.getFunctionName(), std::ref(stmt)});
}

void ConcreteInterpreter::visit(PrintStatement& stmt)
{
    if (stmt.getExpression())
    {
        RuntimeValue value = stmt.getExpression()->accept(*this);

        std::visit([](const auto& val)
        {
            using T = std::decay_t<decltype(val)>;
            if constexpr (std::is_same_v<T, bool>)
            {
                std::cout << std::boolalpha << val << '\n';
            }
            else
            {
                std::cout << val << '\n';
            }
        }, value);
    }
}

RuntimeValue ConcreteInterpreter::visit(VariableExpression& expr)
{
    const std::string& name = expr.getName();

    // looks for the variable on the last environment sitting on the stack
    for (auto it = m_environmentStack.rbegin(); it != m_environmentStack.rend(); ++it)
    {
        if (it->contains(name))
        {
            return it->at(name);
        }
    }

    throw std::runtime_error("Laufzeitfehler: Undefinierte Variable '" + name + "'.");
}

RuntimeValue ConcreteInterpreter::visit(FunctionCallExpression& expr)
{
    std::string functionName = expr.getFunctionName();
    if (m_functions.find(functionName) == m_functions.end())
    {
        throw std::runtime_error("Laufzeitfehler: Undefinierte Funktion '" + functionName + "()' aufgerufen.");
    }

    FunctionDeclarationStatement functionStmt = m_functions.at(functionName);

    functionStmt.getBlockStatement()->accept(*this);

    return false;
}

void ConcreteInterpreter::printVariables() const
{
    std::cout << "\n=== Variables (Global Scope) ===" << std::endl;

    if (!m_environmentStack.empty())
    {
        for (const auto& [name, value] : m_environmentStack.front())
        {
            std::cout << name << " = ";
            std::visit([](const auto& v)
            {
                std::cout << std::boolalpha << v;
            }, value);
            std::cout << std::endl;
        }
    }
}
