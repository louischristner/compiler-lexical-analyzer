#include <cstring>
#include <algorithm>

#include "../headers/lexical_analyzer.hpp"

/**
 * @brief Check if input is a keyword
 *
 * @param input input string to check
 * @return true if input is a keyword, false otherwise
 */
bool isKeyword(const std::string &input)
{
    return (
        input == "if" || input == "IF" ||
        input == "else" || input == "ELSE" ||
        input == "while" || input == "WHILE" ||
        input == "return" || input == "RETURN"
    );
}

/**
 * @brief Apply transform function to the characters of a string
 *
 * @param str string to transform
 * @param transform_func transform function
 * @return string result of transformation
 */
std::string str_transform(const std::string &str, int (*transform_func)(int v))
{
    std::string result = str;

    std::transform(result.begin(), result.end(), result.begin(),
        [transform_func](const char &c){ return transform_func(c); });

    return result;
}
