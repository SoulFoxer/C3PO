//
// Created by leonw on 17.01.2026.
//

#ifndef C3PO_FORLOOPSTATEMENT_HPP
#define C3PO_FORLOOPSTATEMENT_HPP
#include <memory>
#include <vector>
#include <string>
#include "Statement.hpp"

class ForLoopStatement : public Statement
{
    std::vector<std::unique_ptr<Statement>> body;

public:
    ForLoopStatement(std::vector<std::unique_ptr<Statement>> body) : body(std::move(body))
    {
    }


    virtual std::string toString() const override
    {
        std::string result;

        for (auto& statement : body)
        {
            result += statement->toString();
        }
        return "for loop "+ result+ ",";
        return "for loop";
    }

    std::vector<std::unique_ptr<Statement>>& getBody()
    {
        return body;
    }
};

#endif //C3PO_FORLOOPSTATEMENT_HPP
