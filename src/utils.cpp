#include "../headers/lexical_analyzer.hpp"
#include <cstring>

bool isKeyword(const std::string input) {
    if (std::strcmp(input.c_str(), "if") == 0 || std::strcmp(input.c_str(), "IF") == 0 ||
        std::strcmp(input.c_str(), "else") == 0 || std::strcmp(input.c_str(), "ELSE") == 0 ||
        std::strcmp(input.c_str(), "while") == 0 || std::strcmp(input.c_str(), "WHILE") == 0 ||
        std::strcmp(input.c_str(), "return") == 0 || std::strcmp(input.c_str(), "RETURN") == 0)
            return true;
    return false;
}