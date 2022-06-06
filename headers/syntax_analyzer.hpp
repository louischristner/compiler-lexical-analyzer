#ifndef SYNTAX_ANALYZER_HPP_
#define SYNTAX_ANALYZER_HPP_

#include "lexical_analyzer.hpp"
#include "exceptions/SyntaxErrorException.hpp"
#include <algorithm>
#include <map>

enum ACTION {
    SWAP,
    REPLACE,
    GOTO,
    ACC
};

struct actionState {
    ACTION actionType;
    int index;
};

struct grammarElement {
    std::vector<std::string> listEl;
    std::string type;
};

struct syntaxAnalyzer {
    std::vector<grammarElement> slrGrammar;
    std::map<int, std::map<std::string, actionState>> lrTable;

    std::vector<std::string> nttStack;
    std::vector<int> stateStack;
};

void syntax_analyzer(Scanner scanner);

#endif /* !SYNTAX_ANALYZER_HPP_ */