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
        vtype_analyzer,
        integer_analyzer,
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

    std::size_t func_ptrs_size = sizeof(func_ptrs) / sizeof(func_ptrs[0]);

    for (std::size_t index = 0; index < input.size(); tokenFound = false) {
        while (input[index] == ' ' || input[index] == '\n' || input[index] == '\t')
            index++;

        for (std::size_t i_func_ptr = 0; i_func_ptr < func_ptrs_size && index < input.size(); i_func_ptr++)
            if ((tokenFound = func_ptrs[i_func_ptr](input, index, scanner)))
                break;

        if (!tokenFound) {
            throw LexicalErrorException("Error");
        }
    }
}