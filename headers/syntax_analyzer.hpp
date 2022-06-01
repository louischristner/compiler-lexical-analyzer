#ifndef SYNTAX_ANALYZER_HPP_
#define SYNTAX_ANALYZER_HPP_

#include <vector>
#include <string>
#include <map>

enum ACTION {
    SWAP,
    REPLACE,
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



#endif /* !SYNTAX_ANALYZER_HPP_ */