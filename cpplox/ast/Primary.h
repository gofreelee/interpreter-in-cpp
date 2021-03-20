#ifndef PRIMARY_H_
#define PRIMARY_H_
#include "Expr.h"
class Primary : public Expr
{
private:
    Token primary_value;

public:
    Primary(const Token &token) : primary_value(token) {}
};

#endif