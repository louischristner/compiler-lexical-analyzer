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

    // iterate through input until character isn't a digit or end of input
    for (; isdigit(input[cpy_index]) && cpy_index < input.size(); cpy_index++, int_length++);

    if (int_length > 0) {
        substr = input.substr(index, cpy_index - index);
        // handle specific -0 case
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
        for (idxStringEnd = idxStringBegin; idxStringEnd < input.length(); idxStringEnd++)
            if (input[idxStringEnd] == '"')
                break;

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

    // if first character isn't alphabetic then return false
    // identifier should start with english letter
    if (!isalpha(input[index]))
        return false;

    // iterate through input until character isn't alphanumeric or end of input
    for (; isalnum(input[cpy_index]) && cpy_index < input.size(); cpy_index++, substr_len++);

    if (substr_len > 0) {
        substr = input.substr(index, substr_len);
        // if result is a keyword then return false
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

    // for each operation symbol check if character is equal
    // if character is equal to an operation symbol then add it to token list
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
    std::string comparisons[] = { "==", "!=", "<=", ">=", "<", ">" };

    // for each comparison symbol check if substring is equal
    // if substring is equal to a comparison symbol then add it to token list
    for (const std::string &comparison : comparisons) {
        substr = input.substr(index, comparison.size());
        if (comparison == substr) {
            scanner.tokens.push_back({ "COMP", comparison });
            index += comparison.size();
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

    // for each symbol check if character is equal
    // if character is equal to a symbol then add it to token list
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
    // if character is not a comma then return false
    // otherwise add it to the token list
    if (input[index] != ',')
        return false;

    scanner.tokens.push_back({ "COMMA", "" });
    index += 1;

    return true;
}
