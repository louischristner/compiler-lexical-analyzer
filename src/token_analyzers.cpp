#include "../headers/lexical_analyzer.hpp"

bool vtype_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool integer_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    std::size_t int_length = 0;
    std::size_t cpy_index = index;
    std::string substr;

    if (input[cpy_index] == '-') {
        // check if previous element is an ID or an INTEGER
        // if it is true then - is an OP
        if (scanner.tokens.size() > 0)
            if (scanner.tokens.back().name == "ID" || scanner.tokens.back().name == "INTEGER")
                return false;

        cpy_index++;
    }

    for (; isdigit(input[cpy_index]); cpy_index++, int_length++);

    if (int_length > 0) {
        substr = input.substr(index, cpy_index - index);
        if (substr == "-0")
            return false;
        scanner.tokens.push_back({ "INTEGER", substr });
        index = cpy_index;
        return true;
    }

    return false;
}

bool string_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    // set starting/ending idx of string's value between symbol '"'
    std::size_t idxStringBegin(0);
    std::size_t idxStringEnd(0);
    std::size_t tmpIndex = index;
            
            
    if (input.at(std::size_t(tmpIndex)) == '"') {
        char c;
        // setting starting pos of string's value after symbol '"'
        idxStringBegin = std::size_t(tmpIndex + 1);
        // skipping starting symbol of string in order
        // to parse the string value
        tmpIndex++;
        // for each iteration we will :
        // - checking for the ending symbol, if there is one then we break
        // - checking for any combinations of digits, English letters, and blanks
        while (tmpIndex < input.length()) {
            c = input[tmpIndex];
            if (c == '"') {
                idxStringEnd = std::size_t(tmpIndex);
                break;
            }
            if (c == ' ' || isdigit(c) || isalpha(c))
                    tmpIndex++;
            else
                return false;
        }
    } else
        return false;

    // Once the input is parsed, we will make sure that
    // we're ending with a symbol '"' at the end
    if (input.at(std::size_t(tmpIndex)) != '"' || idxStringEnd == static_cast<size_t>(0))
        return false;
    
    // Incrementing index in order to parse for the next symbol in the main loop
    tmpIndex++;
    index = tmpIndex;

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
