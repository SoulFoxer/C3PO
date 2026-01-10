//
// Created by leonw on 10.01.2026.
//

#ifndef C3PO_STATEMENT_HPP
#define C3PO_STATEMENT_HPP
#include <string>


class Statement
{
public:
    virtual ~Statement() = default;
    virtual std::string toString() const = 0;
};


#endif //C3PO_STATEMENT_HPP