//
// Created by leonw on 25.09.2025.
//

#include "../include/Lexer.hpp"
#include "../include/Token.hpp"

void Lexer::advance()
{
    m_current++;
}

bool Lexer::isAtEnd() const
{
    return m_current >= m_source.length();
}

char Lexer::getCurrentChar() const
{
    // Schutz gegen Out-of-bounds; liefert definierte leere Zeichenmarke
    if (m_current >= m_source.size())
    {
        return '\0';
    }
    return m_source.at(m_current);
}

std::vector<Token> Lexer::lex()
{
    std::vector<Token> tokens;
    while (!isAtEnd())
    {
        const char currentChar = getCurrentChar();

        switch (currentChar)
        {
        case ' ':
        case '\r':
        case '\t':
        case '\n':
            // increment line number here
            advance();
            break;
        case '+':
            {
                Token token(TokenType::PLUS, "PLUS +");
                tokens.push_back(std::move(token));
                advance();
            }

        case '-':
            {
                Token token(TokenType::MINUS, "Minus -");
                tokens.push_back(std::move(token));
                advance();
            }
        }
    }
    return tokens;
}
