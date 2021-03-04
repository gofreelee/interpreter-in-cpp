#ifndef SCANNER_H_
#define SCANNER_H_
#include <vector>
#include <string>
#include "Token.h"
class Scanner
{
private:
    std::string sourceCode;
    int start = 0;
    int current = 0;
    int line = 1;
    std::vector<Token> tokens; //lex result

    bool isAtEnd();

public:
    Scanner(std::string code) : sourceCode(code) {}
    std::vector<Token> scanTokens();
    Token scanToken();
    char advance();
    void addToken(TokenType type);
    void addToken(TokenType type, Object literal);
    bool match(char expectedChar);
    char peek();
    void string();
    bool isDigit();
    void number();
};
#endif