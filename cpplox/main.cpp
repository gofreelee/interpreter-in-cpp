#include "parser/Scanner.h"
#include "parser/Parser.h"
#include <iostream>
using namespace std;
int main()
{
    const char *source = "1 + 3 - (56 * 32)";
    Scanner scanner(source);
    auto tokens = scanner.scanTokens();
    Parser parser = Parser(tokens);
    Expr* expr = parser.expression();
    for (auto i : tokens)
    {
            std::cout << i.lexeme << endl;
    }
}