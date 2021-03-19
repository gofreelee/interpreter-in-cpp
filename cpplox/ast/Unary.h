#ifndef UNARY_H_
#define UNARY_H_
#include "Expr.h"
class Unary:public Expr
{
private:
    Expr* operand; // 一元表达式
public:
    Unary(Expr* _operand, const Token& _op) : Expr(_op), operand(_operand) {}
};

#endif