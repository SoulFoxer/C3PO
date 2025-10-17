//
// Created by leonw on 05.10.2025.
//

#ifndef C3PO_VARIABLEDECLARATIONSTATEMENT_HPP
#define C3PO_VARIABLEDECLARATIONSTATEMENT_HPP
#include <optional>
#include <string>
#include <memory>
#include <variant>

// Forward-Deklaration oder #include für deine Expression-Klasse
class Expression;

class VariableDeclarationStatement
{
    std::string m_variableName;
    std::optional<std::variant<int,std::string>> m_initialValue;
public:


    VariableDeclarationStatement(std::string name, std::variant<int,std::string> value) : m_variableName(std::move(name)), m_initialValue(value)
    {
    }

    const std::string& getVariableName() const { return m_variableName; }
    const std::optional<std::variant<int, std::string>>& getInitialValue() const { return m_initialValue; }
};


#endif //C3PO_VARIABLEDECLARATIONSTATEMENT_HPP
