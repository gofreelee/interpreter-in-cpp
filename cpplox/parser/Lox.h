#ifndef LOX_H_
#define LOX_H_
#include<string>
class Lox
{
private:
    /* data */
    static bool hadError;
public:
    static void runFile(std::string path);
    static void runPrompt();
    static void run();
    static void error(int line, std::string message);
    static void report(int line, std::string where, std::string message);
    
    Lox(/* args */);
    ~Lox() = default;
};

void Lox::error(int line, std::string message)
{
    printf("in line %d , error is : %s \n", line, message.c_str());
}


#endif