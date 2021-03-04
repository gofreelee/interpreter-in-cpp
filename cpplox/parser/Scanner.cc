#include "Scanner.h"
#include "Lox.h"
#include <iostream>
std::map<std::string, TokenType> Scanner::reservedWords = {
    {"and", AND},
    {"class", CLASS},
    {"else", ELSE},
    {"false", FALSE},
    {"for", FOR},
    {"fun", FUN},
    {"if", IF},
    {"nil", NIL},
    {"or", OR},
    {"print", PRINT},
    {"return", RETURN},
    {"super", SUPER},
    {"this", THIS},
    {"true", TRUE},
    {"var", VAR},
    {"while", WHILE}};

std::vector<Token> Scanner::scanTokens()
{
    while (!isAtEnd())
    {
        scanToken();
        start = current;
    }
    return tokens;
}

void Scanner::scanToken()
{
    char ch = advance();
    switch (ch)
    {
    case '(':
        addToken(LEFT_PAREN);
        break;
    case ')':
        addToken(RIGHT_PAREN);
        break;
    case '{':
        addToken(LEFT_BRACE);
        break;
    case '}':
        addToken(RIGHT_BRACE);
        break;
    case ',':
        addToken(COMMA);
        break;
    case '.':
        addToken(DOT);
        break;
    case '+':
        addToken(PLUS);
        break;
    case '-':
        addToken(MINUS);
        break;
    case '*':
        addToken(STAR);
        break;
    case ';':
        addToken(SEMICOLON);
        break;
    case '!':
        addToken(match('=') ? BANG_EQUAL : BANG);
        break;
    case '=':
        addToken(match('=') ? EQUAL_EQUAL : EQUAL);
        break;
    case '<':
        addToken(match('=') ? LESS_EQUAL : LESS);
        break;
    case '>':
        addToken(match('=') ? GREATER_EQUAL : GREATER);
        break;
    case '/':
        if (match('/'))
        {
            while (peek() != '\n' && peek() != '\0')
                advance(); // 处理注释， 两个/后面一直读，直到读到换行符号，或者文件读完
        }
        else
        {
            addToken(SLASH);
        }
        break;
    case ' ':
    case '\r':
    case '\t':
        break;
    case '\n':
        ++line;
        break;
    case '"':
        string();
        break;
    default:
        if (isDigit(ch))
        {
            number();
        }
        else if (isAlphabet(ch))
        {
            while (isAlphabet(peek()) || isDigit(peek()))
            {
                advance();
            }
            std::string text = sourceCode.substr(start, current - start);
            if (Scanner::reservedWords.count(text) != 0)
            {
                //reservedword
                addToken(reservedWords[text], new std::string(std::move(text)));
            }
            else
            {
                addToken(IDENTIFIER, new std::string(std::move(text)));
            }
        }
        else
        {
            Lox::error(line, "unexpected character.");
        }
        break;
    }
}

char Scanner::advance()
{
    if (current >= sourceCode.length())
    {
        // at the end of source code
        return '\0';
    }
    return sourceCode.c_str()[current++]; //maybe influence performance
}

void Scanner::addToken(TokenType type)
{
    addToken(type, nullptr);
}

void Scanner::addToken(TokenType type, Object literal)
{
    std::string tokenValue = sourceCode.substr(start, current - start);
    tokens.push_back(std::move(
        Token(type, tokenValue, literal, line)));
}

bool Scanner::match(char expectedChar)
{
    //if not match, return . else need to add one to current
    if (current >= sourceCode.length())
        return false;
    if (expectedChar != sourceCode.c_str()[current])
        return false;
    ++current;
    return true;
}

char Scanner::peek()
{
    if (current >= sourceCode.length())
        return '\0';
    return sourceCode.c_str()[current];
}

void Scanner::string()
{
    while (peek() != '"' && !isAtEnd())
    {
        if (peek() == '\n')
            ++line;
        advance();
    }
    if (isAtEnd())
    {
        Lox::error(line, "");
        return;
    }
    advance();
    std::string text = sourceCode.substr(start + 1, current - (start + 1));

    addToken(STRING, new std::string(std::move(text)));
}

void Scanner::number()
{
    while (isdigit(peek()) && !isAtEnd())
    {
        advance();
    }
    if (peek() == '.' && isdigit(nextPeek()))
    {
        advance();
        while (isdigit(peek()) && !isAtEnd())
            advance();
    }
    std::string numberText = sourceCode.substr(start, current - start);
    addToken(NUMBER, new std::string(std::move(numberText)));
}

bool Scanner::isAlphabet(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           ch == '_';
}

bool Scanner::isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

char Scanner::nextPeek()
{
    if (current + 1 >= sourceCode.length())
        return '\0';
    return sourceCode.c_str()[current + 1];
}