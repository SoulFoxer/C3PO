#ifndef C3PO_CONCRETEINTERPRETER_HPP
#define C3PO_CONCRETEINTERPRETER_HPP

#include "visitor/Visitor.hpp"
#include <map>
#include <string>
#include <vector>

class FunctionCallExpression;

class ConcreteInterpreter : public Visitor {
private:
    std::vector<std::map<std::string, RuntimeValue>> m_environmentStack;
    std::map<std::string, std::reference_wrapper<FunctionDeclarationStatement>> m_functions;

public:
    explicit ConcreteInterpreter();
    void visit(ProgramStatement &stmt) override;
    void visit(VariableDeclarationStatement &stmt) override;
    void visit(ForLoopStatement &stmt) override;
    void visit(BlockStatement &block) override;
    void visit(FunctionDeclarationStatement &stmt) override;
    void visit(PrintStatement &stmt) override;
    void visit(IfStatement& stmt) override;
    void visit(ExpressionStatement &stmt) override;
    
    RuntimeValue visit(LiteralExpression &stmt) override;
    RuntimeValue visit(BinaryExpression &stmt) override;
    RuntimeValue visit(VariableExpression &expr) override;
    RuntimeValue visit(FunctionCallExpression &expr) override;

    void printVariables() const;
};

#endif //C3PO_CONCRETEINTERPRETER_HPP