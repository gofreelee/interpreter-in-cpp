#ifndef TOKEN_H_
#define TOKEN_H_
#include <string>
using Object = void *;

enum TokenType
{
    LEFT_PAREN = 0,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    STAR,

    //One or two character tokens
    BANG,
    BANG_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,

    //Literals
    IDENTIFIER,
    STRING,
    NUMBER,

    //keyword
    AND,
    CLASS,
    ELSE,
    FALSE,
    FUN,
    FOR,
    IF,
    NIL,
    OR,
    PRINT,
    RETURN,
    SUPER,
    THIS,
    TRUE,
    VAR,
    WHILE,
    NOTHING,
    _EOF_
};

class Token
{

private:
    TokenType type;
    Object literal;
    int line;

public:
    std::string lexeme;
    Token()
    {
        type = NOTHING;
    }
    //constructor
    Token(TokenType type, std::string lexeme, Object literal, int line) : type(type), lexeme(lexeme),
                                                                          literal(literal), line(line)
    {
    }

    std::string toString()
    {

        return *(static_cast<std::string *>(literal));
    }
    TokenType getTokenType() { return type; }
};
#endif