//
// Created by leonw on 17.01.2026.
//

#ifndef C3PO_EXPRESSION_HPP
#define C3PO_EXPRESSION_HPP

class Expression
{
    public:
    virtual ~Expression() = default;
    virtual std::string toString() const = 0;
};

#endif //C3PO_EXPRESSION_HPP