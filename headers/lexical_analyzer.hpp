#ifndef LEXICAL_ANALYZER_HPP_
#define LEXICAL_ANALYZER_HPP_

#include <list>
#include <string>

struct Token {
    std::string name;
    std::string value;
};

struct Scanner {
    std::list<Token> tokens;
};

void lexical_analyzer(const std::string &input, Scanner &);

bool vtype_analyzer(const std::string &input, Scanner &);
bool integer_analyzer(const std::string &input, Scanner &);
bool string_analyzer(const std::string &input, Scanner &);
bool identifier_analyzer(const std::string &input, Scanner &);
bool keyword_analyzer(const std::string &input, Scanner &);
bool arithmetic_analyzer(const std::string &input, Scanner &);
bool assignment_analyzer(const std::string &input, Scanner &);
bool comparison_analyzer(const std::string &input, Scanner &);
bool semi_analyzer(const std::string &input, Scanner &);
bool brace_analyzer(const std::string &input, Scanner &);
bool paren_analyzer(const std::string &input, Scanner &);
bool comma_analyzer(const std::string &input, Scanner &);

#endif /* !LEXICAL_ANALYZER_HPP_ */
