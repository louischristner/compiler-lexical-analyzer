#include <iostream>
#include <fstream>

#include "headers/lexical_analyzer.hpp"

int main(int ac, char **av)
{
    std::ifstream cFile;
    Scanner scanner;
    std::string input = "";

    if (ac > 1) input = av[1];

    cFile = std::ifstream(input);

    if (cFile.is_open()) {
        std::string line;
        while(std::getline(cFile, line)) {
            // std::cout << line << std::endl;
            lexical_analyzer(line, scanner);
        }
    }

    // lexical_analyzer(input, scanner);

    for (std::size_t index = 0; index < scanner.tokens.size(); index++) {
        Token token = scanner.tokens[index];
        std::cout << "<" << token.name << "," << token.value << ">\n";
    }

    return 0;
}