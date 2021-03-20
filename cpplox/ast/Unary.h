#ifndef UNARY_H_
#define UNARY_H_
#include "Expr.h"
class Unary : public Expr
{
private:
    Expr *operand; // 一元表达式
    Token op;
public:
    Unary(Expr *_operand, const Token &_op) : op(_op), operand(_operand) {}
};

#endif