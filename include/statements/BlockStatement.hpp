//
// Created by leonw on 19.01.2026.
//

#ifndef C3PO_BLOCKSTATEMENT_HPP
#define C3PO_BLOCKSTATEMENT_HPP
#include <memory>
#include <vector>

#include "Statement.hpp"

class BlockStatement: public Statement
{
    std::vector<std::unique_ptr<Statement>> statements;

public:
    BlockStatement(std::vector<std::unique_ptr<Statement>> statements) : statements(std::move(statements)) {}

    virtual std::string toString() const override
    {
        std::string result;
        result += "{";
        for (auto& statement : statements)
        {
            result += statement->toString();
        }
        result += "}";
        return result;
    }
    const std::vector<std::unique_ptr<Statement>>& getStatements() const { return statements; }
};

#endif //C3PO_BLOCKSTATEMENT_HPP