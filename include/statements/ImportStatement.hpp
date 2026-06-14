//
// Created by leonw on 14.06.2026.
//

#ifndef C3PO_IMPORTSTATEMENT_HPP
#define C3PO_IMPORTSTATEMENT_HPP
#include "Statement.hpp"

class ImportStatement : public Statement
{
private:
    std::string m_filePath;

public:
    explicit ImportStatement(std::string filePath);
    [[nodiscard]] const std::string& getFilePath() const;
    void accept(Visitor& visitor) override;
    [[nodiscard]] std::string toString() const override;
};

#endif //C3PO_IMPORTSTATEMENT_HPP
