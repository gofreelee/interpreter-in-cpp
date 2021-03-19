#ifndef PARSER_H_
#define PARSER_H_
#include "Token.h"
#include "../ast/Expr.h"
#include <vector>
using namespace std;
// expression     → equality ;
// equality       → comparison ( ( "!=" | "==" ) comparison )* ;
// comparison     → term ( ( ">" | ">=" | "<" | "<=" ) term )* ;
// term           → factor ( ( "-" | "+" ) factor )* ;
// factor         → unary ( ( "/" | "*" ) unary )* ;
// unary          → ( "!" | "-" ) unary
//                | primary ;
// primary        → NUMBER | STRING | "true" | "false" | "nil"
//                | "(" expression ")" ;
class Parser
{
private:
    vector<Token> tokenList;
    int curr_cursor = 0;

public:
    Parser() {}
    Parser(const vector<Token> &list) : tokenList(list) {}
    Expr* expression();
    Expr* equality();
    Expr* comparison();
    Expr* term();
    Expr* factor();
    Expr* unary();
    Expr* primary();
    bool match(TokenType expectType);
    Token eat(); // eattoken;
};

#endif