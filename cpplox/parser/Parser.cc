#include "Parser.h"
#include "../ast/BinaryExpr.h"
#include "../ast/Unary.h"
#include "../ast/Primary.h"
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
        Token op = eat();
        Expr *right = comparison();
        expr = new BinaryExpr(expr, right, op);
    }
    return expr;
}

Expr *Parser::comparison()
{
    Expr *expr = term();
    while (match(GREATER) || match(GREATER_EQUAL) || match(LESS) || match(LESS_EQUAL))
    {
        Token op = eat();
        Expr *right = term();
        expr = new BinaryExpr(expr, right, op);
    }
}

Expr *Parser::term()
{
    Expr *expr = factor();
    while (match(MINUS) || match(PLUS))
    {
        Token op = eat();
        Expr *right = factor();
        expr = new BinaryExpr(expr, right, op);
    }
    return expr;
}

Expr *Parser::factor()
{
    Expr *expr = unary();
    while (match(SLASH) || match(STAR))
    {
        Token op = eat();
        Expr *right = unary();
        expr = new BinaryExpr(expr, right, op);
    }
    return expr;
}

Expr *Parser::unary()
{
    if (match(MINUS) || match(BANG))
    {
        return new Unary(
            unary(),
            eat());
    }
    return primary();
}

Expr *Parser::primary()
{
    if (match(LEFT_PAREN))
    {
        Expr *primary_expr = expression();
        match(RIGHT_PAREN) ? eat() : Token();
        return primary_expr;
    }
    if (match(NUMBER) || STRING || TRUE || FALSE || NIL)
        return new Primary(eat());
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
