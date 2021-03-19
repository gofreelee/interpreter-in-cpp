#include "Parser.h"
// expression     → equality ;
// equality       → comparison ( ( "!=" | "==" ) comparison )* ;
// comparison     → term ( ( ">" | ">=" | "<" | "<=" ) term )* ;
// term           → factor ( ( "-" | "+" ) factor )* ;
// factor         → unary ( ( "/" | "*" ) unary )* ;
// unary          → ( "!" | "-" ) unary
//                | primary ;
// primary        → NUMBER | STRING | "true" | "false" | "nil"
//                | "(" expression ")" ;
Expr* Parser::expression(){
    return nullptr;
}

Expr* Parser::equality(){}



bool Parser::match(TokenType type)
{
    if (curr_cursor >= tokenList.size())
        return false;
    return tokenList[curr_cursor++].getTokenType() == type;
}

Token Parser::eat() {
    if(curr_cursor >= tokenList.size())
    {
        return Token();
    }
    return tokenList[curr_cursor++];    

}
