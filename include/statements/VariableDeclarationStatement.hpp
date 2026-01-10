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
        std::string result = "var " + m_variableName;

        // 1. Check if the Optional has a value
        if (m_initialValue.has_value()) {

            // 2. Dereference the optional (*m_initialValue) to get the variant.
            // 3. Use std::visit to handle the different types inside the variant.
            std::string valueStr = std::visit([](auto&& arg) -> std::string {
                using T = std::decay_t<decltype(arg)>;

                if constexpr (std::is_same_v<T, int>) {
                    return std::to_string(arg);
                }
                else if constexpr (std::is_same_v<T, std::string>) {
                    return "\"" + arg + "\""; // Wrap string literals in quotes
                }
                return "";
            }, *m_initialValue);

            result += " = " + valueStr;
        }

        result += ";";
        return result;
    }
};


#endif //C3PO_VARIABLEDECLARATIONSTATEMENT_HPP
