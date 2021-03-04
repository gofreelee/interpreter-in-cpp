#include "parser/Scanner.h"
#include <iostream>
using namespace std;
int main()
{
    const char *source = "for (var a = 1; a < 10; a = a + 1) {print a;}";
    Scanner scanner(source);
    auto tokens = scanner.scanTokens();
    for (auto i : tokens)
    {
            std::cout << i.lexeme << endl;
    }
}