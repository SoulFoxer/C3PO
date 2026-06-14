//
// Created by leonw on 27.01.2026.
//

#ifndef C3PO_VISITOR_HPP
#define C3PO_VISITOR_HPP
#include <variant>
#include <string>

class FunctionCallExpression;
using RuntimeValue = std::variant<int, std::string, bool>;

class LiteralExpression;
class FunctionDeclarationStatement;
class VariableDeclarationStatement;
class ForLoopStatement;
class BlockStatement;
class ProgramStatement;
class BinaryExpression;
class VariableExpression;
class PrintStatement;
class IfStatement;
class FunctionDeclarationStatement;
class ExpressionStatement;
class ImportStatement;

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(VariableDeclarationStatement &stmt) = 0;

    virtual void visit(ForLoopStatement &stmt) = 0;

    virtual void visit(BlockStatement &stmt) = 0;

    virtual void visit(ProgramStatement &stmt) = 0;

    virtual void visit(FunctionDeclarationStatement &stmt) = 0;
    virtual RuntimeValue visit(FunctionCallExpression &expr) = 0;

    virtual RuntimeValue visit(LiteralExpression &expr) = 0;

    virtual RuntimeValue visit(BinaryExpression &stmt) = 0;

    virtual void visit(PrintStatement &stmt) = 0;

    virtual RuntimeValue visit(VariableExpression &expr) = 0;
    virtual void visit(IfStatement &stmt) = 0;
    virtual void visit(ExpressionStatement &stmt) = 0;
    virtual void visit(ImportStatement &stmt) = 0;
};

#endif //C3PO_VISITOR_HPP
