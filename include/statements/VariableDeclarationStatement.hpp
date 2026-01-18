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

#include "../Parser.hpp"

// Forward-Deklaration oder #include für deine Expression-Klasse


class VariableDeclarationStatement : public Statement
{
    std::string m_variableName;
    std::optional<std::variant<int, std::string>> m_initialValue;

public:
    VariableDeclarationStatement(std::string name, std::variant<int, std::string> value) :
        m_variableName(std::move(name)), m_initialValue(value)
    {
    }

    const std::string& getVariableName() const { return m_variableName; }
    const std::optional<std::variant<int, std::string>>& getInitialValue() const { return m_initialValue; }


    std::string toString() const override
    {
        std::string valueStr = "null";
        if (m_initialValue.has_value())
        {

            if (std::holds_alternative<int>(m_initialValue.value()))
            {
                valueStr = std::to_string(std::get<int>(m_initialValue.value()));
            }

            else if (std::holds_alternative<std::string>(m_initialValue.value()))
            {
                valueStr = std::get<std::string>(m_initialValue.value());
            }
        }
        return "VariableDeclarationStatement(" + m_variableName + " = " + valueStr + ")";
    }
};


#endif //C3PO_VARIABLEDECLARATIONSTATEMENT_HPP
