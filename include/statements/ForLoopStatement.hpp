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
    std::unique_ptr<BlockStatement> body;

public:
    ForLoopStatement(std::unique_ptr<BlockStatement> body) : body(std::move(body))
    {
    }


    virtual std::string toString() const override
    {
        std::string result;

        result += "for";
        result += " {";
        for (auto& statement : body.get()->getStatements())
        {
            result += statement->toString()+ ", ";
        }
        result += "}";
        return result;
    }

    /*std::vector<std::unique_ptr<Statement>>& getBody()
    {
        return body;
    }*/

    std::unique_ptr<BlockStatement>& getBody()
    {
        return body;
    }

};

#endif //C3PO_FORLOOPSTATEMENT_HPP
