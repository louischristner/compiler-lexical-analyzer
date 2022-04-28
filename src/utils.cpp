#include <cstring>
#include <algorithm>

#include "../headers/lexical_analyzer.hpp"

bool isKeyword(const std::string input)
{
    return (
        input == "if" || input == "IF" ||
        input == "else" || input == "ELSE" ||
        input == "while" || input == "WHILE" ||
        input == "return" || input == "RETURN"
    );
}

std::string str_transform(const std::string &str, int (*transform_func)(int v))
{
    std::string result = str;

    std::transform(result.begin(), result.end(), result.begin(),
        [transform_func](const char &c){ return transform_func(c); });

    return result;
}
