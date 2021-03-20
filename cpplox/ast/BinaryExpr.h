#ifndef BINARY_EXPR_H_
#define BINARY_EXPR_H_
#include "Expr.h"
class BinaryExpr : public Expr
{
private:
    //two operator
    Expr *left;
    Expr *right;
    Token op;
public:
    BinaryExpr(Expr *_left, Expr *_right, Token _op) :  op(_op), left(_left), right(_right)
    {
    }
};

#endif