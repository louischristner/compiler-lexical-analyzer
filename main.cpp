#include <iostream>

#include "headers/lexical_analyzer.hpp"

int main(void)
{
    Scanner scanner;

    lexical_analyzer("", scanner);

    while (scanner.tokens.size() > 0) {
        Token token = scanner.tokens.front();

        std::cout << "<" << token.name << "," << token.value << ">\n";
        scanner.tokens.pop_front();
    }

    return 0;
}