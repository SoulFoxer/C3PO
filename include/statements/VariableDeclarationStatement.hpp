//
// Created by leonw on 05.10.2025.
//

#ifndef C3PO_VARIABLEDECLARATIONSTATEMENT_HPP
#define C3PO_VARIABLEDECLARATIONSTATEMENT_HPP
#include <optional>
#include <string>
#include <memory>
#include <variant>
#include "Statement.hpp"
#include "Token.hpp"

class VariableDeclarationStatement : public Statement
{
    std::string m_variableName;
    std::optional<Token> m_initialValue;

public:
    VariableDeclarationStatement(std::string name, Token value)
        : m_variableName(std::move(name))
        , m_initialValue(std::move(value))
    {
    }

    const std::string& getVariableName() const { return m_variableName; }
    const std::optional<Token>& getInitialValue() const { return m_initialValue; }

    std::string toString() const override
    {
        std::string valueStr = "null";

        if (m_initialValue.has_value())
        {
            const Token& token = m_initialValue.value();

            std::visit([&valueStr](const auto& val) {
                if constexpr (std::is_same_v<decltype(val), const int&>)
                {
                    valueStr = std::to_string(val);
                }
                else
                {
                    valueStr = "\"" + val + "\"";
                }
            }, token.getValue());
        }

        return "VariableDeclarationStatement(" + m_variableName + " = " + valueStr + ")";
    }
};

#endif //C3PO_VARIABLEDECLARATIONSTATEMENT_HPP