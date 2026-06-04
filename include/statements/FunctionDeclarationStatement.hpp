//
// Created by leonw on 15.03.2026.
//

#ifndef C3PO_FUNCTIONDECLARATIONSTATEMENT_HPP
#define C3PO_FUNCTIONDECLARATIONSTATEMENT_HPP
#include <memory>
#include <string>
#include "Statement.hpp"
#include "../token/Token.hpp"
#include "BlockStatement.hpp"
#include "../include//visitor/Visitor.hpp"


class Visitor;
class BlockStatement;

class FunctionDeclarationStatement: public Statement
{
public:
    explicit FunctionDeclarationStatement(const std::string& functionName, const std::shared_ptr<BlockStatement>& block_statement);
    void accept(Visitor& visitor) override;

    ~FunctionDeclarationStatement() override = default;
    std::string toString() const override;
    std::string getFunctionName() const;
    std::shared_ptr<BlockStatement> getBlockStatement() const;

private:
    std::string m_functionName;
    std::shared_ptr<BlockStatement> m_blockStatement;



};
#endif //C3PO_FUNCTIONDECLARATIONSTATEMENT_HPP

