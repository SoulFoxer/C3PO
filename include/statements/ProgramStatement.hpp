//
// Created by leonw on 23.01.2026.
//

#ifndef C3PO_PROGRAM_HPP
#define C3PO_PROGRAM_HPP
#include <memory>
#include <vector>

#include "Statement.hpp"

class ProgramStatement : public Statement
{
    std::vector<std::unique_ptr<Statement>> m_statements;

public:
    ProgramStatement(std::vector<std::unique_ptr<Statement>> statements) : m_statements(std::move(statements))
    {
    }

    std::string toString() const override
    {
        std::string result;
        for (const auto& statement : m_statements)
        {
            result += statement->toString() + "\n";
        }
        return result;
    }

    const std::vector<std::unique_ptr<Statement>>& getStatements() const
    {
        return m_statements;
    }
};

#endif //C3PO_PROGRAM_HPP
