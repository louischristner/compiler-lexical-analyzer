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

#endif /* !LEXICAL_ANALYZER_HPP_ */
