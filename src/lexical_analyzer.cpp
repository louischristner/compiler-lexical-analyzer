#include "../headers/lexical_analyzer.hpp"
#include "../headers/exceptions/LexicalErrorException.hpp"

void lexical_analyzer(const std::string &input, Scanner &scanner)
{
    bool tokenFound = false;
    bool (*func_ptrs[])(
        const std::string &,
        std::size_t &,
        Scanner &
    ) = {
        string_analyzer,
        identifier_analyzer,
        keyword_analyzer,
        arithmetic_analyzer,
        assignment_analyzer,
        comparison_analyzer,
        semi_analyzer,
        brace_analyzer,
        paren_analyzer,
        comma_analyzer
    };

    for (std::size_t index = 0; index < input.size(); tokenFound = false) {
        for (auto &func_ptr : func_ptrs)
            if ((tokenFound = func_ptr(input, index, scanner)))
                break;

        if (!tokenFound) {
            throw LexicalErrorException("Error");
        }
    }
}