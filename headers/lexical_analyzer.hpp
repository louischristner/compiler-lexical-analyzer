#ifndef LEXICAL_ANALYZER_HPP_
#define LEXICAL_ANALYZER_HPP_

#include <vector>
#include <string>
#include <iostream>

struct Token {
    std::string name;
    std::string value;
};

struct Scanner {
    std::vector<Token> tokens;
};

void lexical_analyzer(const std::string &input, Scanner &);

bool vtype_analyzer(const std::string &input, std::size_t &index, Scanner &);
bool integer_analyzer(const std::string &input, std::size_t &index, Scanner &);
bool string_analyzer(const std::string &input, std::size_t &index, Scanner &);
bool identifier_analyzer(const std::string &input, std::size_t &index, Scanner &);
bool keyword_analyzer(const std::string &input, std::size_t &index, Scanner &);
bool arithmetic_analyzer(const std::string &input, std::size_t &index, Scanner &);
bool assignment_analyzer(const std::string &input, std::size_t &index, Scanner &);
bool comparison_analyzer(const std::string &input, std::size_t &index, Scanner &);
bool semi_analyzer(const std::string &input, std::size_t &index, Scanner &);
bool brace_analyzer(const std::string &input, std::size_t &index, Scanner &);
bool paren_analyzer(const std::string &input, std::size_t &index, Scanner &);
bool comma_analyzer(const std::string &input, std::size_t &index, Scanner &);

#endif /* !LEXICAL_ANALYZER_HPP_ */
