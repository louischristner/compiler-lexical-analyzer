#include "../headers/lexical_analyzer.hpp"
#include "../headers/utils.hpp"

bool vtype_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool integer_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    std::size_t int_length = 0;
    std::size_t cpy_index = index;
    std::string substr;

    std::cout << "bite molle" << std::endl;
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

    std::cout << "bite dur" << std::endl;
    return false;
}

bool string_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    // set starting/ending idx of string's value between symbol '"'
    std::size_t idxStringBegin(index);
    std::size_t idxStringEnd(0);
    // std::size_t tmpIndex = index;

    std::cout << input << std::endl;

    if (input.at(std::size_t(idxStringBegin)) == '"') {
        idxStringBegin += 1;
        char c;

        for (std::size_t i = idxStringBegin; i < input.length(); i++)
            if (input[i] == '"')
                idxStringEnd = i;
 

        for (std::size_t b = idxStringBegin; b < idxStringEnd;) {
            c = input[b];
            if (c == ' ' || isdigit(c) || isalpha(c))
                b++;
            else
                return false;
        }
    }
    
    // Incrementing index in order to parse for the next symbol in the main loop
    index = idxStringEnd + 1;

    Token newToken = {"STRING", std::string(input.begin() + idxStringBegin, input.begin() + idxStringEnd)};
    scanner.tokens.push_back(newToken);

    return true;
}

bool identifier_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    std::size_t substr_len = 0;
    std::size_t cpy_index = index;
    std::string substr;

    if (!isalpha(input[index]))
        return false;

    for (; isalnum(input[cpy_index]); cpy_index++, substr_len++);

    if (substr_len > 0) {
        substr = input.substr(index, substr_len);
        if (isKeyword(substr))
            return false;
        scanner.tokens.push_back({ "ID", substr });
        index = cpy_index;
        return true;
    }

    return false;
}

bool keyword_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{


    return true;
}

bool arithmetic_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    char operations[] = { '+', '-', '*', '/' };

    for (const char &operation : operations) {
        if (operation == input[index]) {
            scanner.tokens.push_back({ "OP", std::string(1, operation) });
            index += 1;
            return true;
        }
    }

    return false;
}

bool assignment_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool comparison_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    std::string substr;
    std::string operations[] = { "<", ">", "==", "!=", "<=", ">=" };

    for (const std::string &operation : operations) {
        substr = input.substr(index, operation.size());
        if (operation == substr) {
            scanner.tokens.push_back({ "COMP", operation });
            index += operation.size();
            return true;
        }
    }

    return false;
}

bool semi_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool brace_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    char symbols[] = { '{', '}' };
    const std::string tokenNames[] = { "LBRACE", "RBRACE" };

    for (std::size_t index = 0; index < 2; index++) {
        if (symbols[index] == input[index]) {
            scanner.tokens.push_back({ tokenNames[index], "" });
            index += 1;
            return true;
        }
    }

    return false;
}

bool paren_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    return false;
}

bool comma_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    if (input[index] != ',')
        return false;

    scanner.tokens.push_back({ "COMMA", "" });
    index += 1;

    return true;
}
