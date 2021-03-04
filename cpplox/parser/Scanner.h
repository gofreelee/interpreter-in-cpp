#ifndef SCANNER_H_
#define SCANNER_H_
#include <vector>
#include <string>
#include <map>
#include "Token.h"

class Scanner
{
private:
    std::string sourceCode;
    int start = 0;
    int current = 0;
    int line = 1;
    std::vector<Token> tokens; //lex result
public:
    static std::map<std::string, TokenType> reservedWords;
    Scanner(std::string code) : sourceCode(code) {}
    std::vector<Token> scanTokens();
    void scanToken();
    bool isAtEnd()
    {
        return current >= sourceCode.length();
    }
    char advance();
    void addToken(TokenType type); // add a token to
    void addToken(TokenType type, Object literal);
    bool match(char expectedChar);
    char peek();
    char nextPeek();
    void string();
    bool isDigit(char ch);
    bool isAlphabet(char ch);
    void number();
};
#endif