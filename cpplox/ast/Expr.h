#ifndef EXPR_H_
#define EXPR_H_
#include "../parser/Token.h"
class Expr
{
private:
    Token op;
public:
    Expr(Token _op):op(_op){}
};
#endif