#include <iostream>

#include "headers/lexical_analyzer.hpp"

int main(int ac, char **av)
{
    Scanner scanner;
    std::string input = "";

    if (ac > 1) input = av[1];

    lexical_analyzer(input, scanner);

    for (std::size_t index = 0; index < scanner.tokens.size(); index++) {
        Token token = scanner.tokens[index];
        std::cout << "<" << token.name << "," << token.value << ">\n";
    }

    return 0;
}