#include "../headers/lexical_analyzer.hpp"
#include <iostream>

bool vtype_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool integer_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool string_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    // set starting/ending idx of string's value between symbol '"'
    std::size_t idxStringBegin(0);
    std::size_t idxStringEnd(0);

    if (input.at(std::size_t(index)) == '"') {
        char c;
        // setting starting pos of string's value after symbol '"'
        idxStringBegin = std::size_t(index + 1);
        // skipping starting symbol of string in order
        // to parse the string value
        index++;
        // for each iteration we will :
        // - checking for the ending symbol, if there is one then we break
        // - checking for any combinations of digits, English letters, and blanks
        while (index < input.length()) {
            c = input[index];
            if (c == '"') {
                idxStringEnd = std::size_t(index);
                break;
            }
            if (c == ' ' || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
                (c >= 'A' || c <= 'Z'))
                index++;
            else
                return false;
        }
    } else
        return false;

    // Once the input is parsed, we will make sure that
    // we're ending with a symbol '"' at the end
    if (input.at(std::size_t(index)) != '"' || idxStringEnd == static_cast<size_t>(0))
        return false;
    
    // Incrementing index in order to parse for the next symbol in the main loop
    index++;

    Token newToken = {"STRING", std::string(input.begin() + idxStringBegin, input.begin() + idxStringEnd)};
    scanner.tokens.push_back(newToken);

    return true;
}

bool identifier_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool keyword_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool arithmetic_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool assignment_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool comparison_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool semi_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool brace_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool paren_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool comma_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}