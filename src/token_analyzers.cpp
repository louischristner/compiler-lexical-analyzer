#include "../headers/lexical_analyzer.hpp"
#include "../headers/utils.hpp"

bool vtype_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    std::string tmpString;
    std::string vtype[] = {"int", "INT", "char", "CHAR"};
    std::size_t tmpIdx = index;

    // Parsing until there is no more alpha characters
    // Pushing alpha characters into a new string
    for (; tmpIdx < input.length() && isalpha(input[tmpIdx]); tmpIdx++)
        tmpString.push_back(input[tmpIdx]);

    // Once we get our new string
    // We will compare to the variable vtype containing all
    // of our VTYPE to see if it matched
    for (int i = 0; i < 4; i++) {
        if (vtype[i] == tmpString) {
            index = tmpIdx;
            Token newToken = {"VTYPE", str_transform(vtype[i], std::tolower)};
            scanner.tokens.push_back(newToken);
            return true;
        }
    }

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
    std::size_t idxStringBegin(index);
    std::size_t idxStringEnd(0);

    // If the char is a double quote
    if (input.at(std::size_t(idxStringBegin)) == '"') {
        idxStringBegin += 1;
        char c;

        // Finding the index of the second quote
        for (std::size_t i = idxStringBegin; i < input.length(); i++)
            if (input[i] == '"')
                idxStringEnd = i;

        // Once we have the index of the second quote
        // We will check if between these two quote there are
        // any combinations of digits, english letters or blanks
        for (std::size_t b = idxStringBegin; b < idxStringEnd;) {
            c = input[b];
            if (c == ' ' || isdigit(c) || isalpha(c))
                b++;
            else
                return false;
        }
    } else {
        return false;
    }

    // Incrementing index in order to parse for the next symbol in the main loop
    // as idxStringEnd corresponds to the index of the second double quote
    // we don't want the for loop in the lexical_analysis.cpp to be stuck on the double quote when
    // going back to the loop.
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
    std::string tmpString;
    std::size_t tmpIdx = index;

    // Checking if the current char is a alpha character
    if (isalpha(input[tmpIdx]))
        // Getting every alpha character and pushing into a new string
        while (isalpha(input[tmpIdx]) && tmpIdx < input.length()) {
            tmpString.push_back(input[tmpIdx]);
            tmpIdx++;
        }

    // Checking if the new string created
    // from the alpha characters corresponds
    // to a character
    if (isKeyword(tmpString)) {
        index = tmpIdx;
        Token newToken = {str_transform(tmpString, std::toupper), ""};
        scanner.tokens.push_back(newToken);
    } else
        return false;

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
    // if current character is equal to a '='
    // then it's a token of type assign
    if (input[index] == '=') {
        Token newToken = {"ASSIGN", ""};
        scanner.tokens.push_back(newToken);
        index++;
        return true;
    }

    return false;
}

bool comparison_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    std::string substr;
    std::string operations[] = { "==", "!=", "<=", ">=", "<", ">" };

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
    // if current character is equal to a ';'
    // then it's a token of type assign
    if (input[index] == ';') {
        Token newToken = {"SEMI", ""};
        scanner.tokens.push_back(newToken);
        index++;
        return true;
    }

    return false;
}

bool brace_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    char symbols[] = { '{', '}' };
    const std::string tokenNames[] = { "LBRACE", "RBRACE" };

    for (std::size_t i = 0; i < 2; i++) {
        if (symbols[i] == input[index]) {
            scanner.tokens.push_back({ tokenNames[i], "" });
            index += 1;
            return true;
        }
    }

    return false;
}

bool paren_analyzer(const std::string &input, std::size_t &index, Scanner &scanner)
{
    // if current character is equal to a '(' or ')'
    // then it's a token of type assign
    if (input[index] == ')') {
        Token newToken = {"RPAREN", ""};
        scanner.tokens.push_back(newToken);
        index++;
        return true;
    } else if (input[index] == '(') {
        Token newToken = {"LPAREN", ""};
        scanner.tokens.push_back(newToken);
        index++;
        return true;
    }

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
