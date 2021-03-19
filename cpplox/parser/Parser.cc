#include "Parser.h"
#include "../ast/BinaryExpr.h"
// expression     → equality ;
// equality       → comparison ( ( "!=" | "==" ) comparison )* ;
// comparison     → term ( ( ">" | ">=" | "<" | "<=" ) term )* ;
// term           → factor ( ( "-" | "+" ) factor )* ;
// factor         → unary ( ( "/" | "*" ) unary )* ;
// unary          → ( "!" | "-" ) unary
//                | primary ;
// primary        → NUMBER | STRING | "true" | "false" | "nil"
//                | "(" expression ")" ;
Expr *Parser::expression()
{

    return equality();
}

Expr *Parser::equality()
{
    Expr *expr = comparison();
    while (match(EQUAL_EQUAL) || match(BANG_EQUAL))
    {
        Token operand = eat();
        Expr *right = comparison();
        expr = new BinaryExpr(expr, right, operand);
    }
    return expr;
}

Expr *Parser::comparison()
{
    Expr *expr = term();
    while (match(GREATER) || match(GREATER_EQUAL) || match(LESS) || match(LESS_EQUAL))
    {
        Token operand = eat();
        Expr *right = term();
        expr = new BinaryExpr(expr, right, operand);
    }
}

Expr *Parser::term()
{
    Expr *expr = factor();
    while(match(MINUS) || match(PLUS))
    {
        Token operand = eat();
        Expr* right = factor();
        expr = new BinaryExpr(expr, right, operand);
    }
    return expr;
}

Expr *Parser::factor() 
{
    
}

Expr *Parser::unary() {}

Expr *Parser::primary()
{
}

bool Parser::match(TokenType type)
{
    if (curr_cursor >= tokenList.size())
        return false;
    return tokenList[curr_cursor++].getTokenType() == type;
}

Token Parser::eat()
{
    if (curr_cursor >= tokenList.size())
    {
        return Token();
    }
    return tokenList[curr_cursor++];
}
