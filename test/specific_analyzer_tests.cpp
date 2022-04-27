#include <criterion/criterion.h>

#include "../headers/lexical_analyzer.hpp"

Test(specific_analyzer_test, test_valid_vtype_char_1)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(vtype_analyzer("char", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "VTYPE");
    cr_assert(scanner.tokens.back().value == "char");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_vtype_char_2)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(vtype_analyzer("CHAR", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "VTYPE");
    cr_assert(scanner.tokens.back().value == "char");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_vtype_int_1)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(vtype_analyzer("int", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "VTYPE");
    cr_assert(scanner.tokens.back().value == "int");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_vtype_int_2)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(vtype_analyzer("INT", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "VTYPE");
    cr_assert(scanner.tokens.back().value == "int");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_integer_1)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(integer_analyzer("0", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "0");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_integer_2)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(integer_analyzer("-1", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "-1");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_integer_3)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(integer_analyzer("10", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "10");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_integer_4)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(integer_analyzer("999", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "999");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_string_1)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(string_analyzer("\"Hello world\"", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "STRING");
    cr_assert(scanner.tokens.back().value == "Hello world");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_string_2)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(string_analyzer("\"My student id is 12345678\"", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "STRING");
    cr_assert(scanner.tokens.back().value == "My student id is 12345678");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_identifier_1)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(identifier_analyzer("i", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "i");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_identifier_2)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(identifier_analyzer("j", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "j");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_identifier_3)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(identifier_analyzer("k", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "k");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_identifier_4)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(identifier_analyzer("abc", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "abc");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_identifier_5)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(identifier_analyzer("ab123", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "ab123");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_identifier_6)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(identifier_analyzer("func1", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "func1");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_keyword_1)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(keyword_analyzer("if", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "IF");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_keyword_2)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(keyword_analyzer("IF", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "IF");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_keyword_3)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(keyword_analyzer("else", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "ELSE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_keyword_4)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(keyword_analyzer("ELSE", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "ELSE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_keyword_5)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(keyword_analyzer("while", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "WHILE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_keyword_6)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(keyword_analyzer("WHILE", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "WHILE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_keyword_7)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(keyword_analyzer("return", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "RETURN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_keyword_8)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(keyword_analyzer("RETURN", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "RETURN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_arithmetic_operators_1)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(arithmetic_analyzer("+", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "OP");
    cr_assert(scanner.tokens.back().value == "+");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_arithmetic_operators_2)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(arithmetic_analyzer("-", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "OP");
    cr_assert(scanner.tokens.back().value == "-");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_arithmetic_operators_3)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(arithmetic_analyzer("*", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "OP");
    cr_assert(scanner.tokens.back().value == "*");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_arithmetic_operators_4)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(arithmetic_analyzer("/", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "OP");
    cr_assert(scanner.tokens.back().value == "/");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_assignment_operators)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(assignment_analyzer("=", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "ASSIGN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_comparison_operators_1)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(comparison_analyzer("<", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "COMP");
    cr_assert(scanner.tokens.back().value == "<");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_comparison_operators_2)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(comparison_analyzer(">", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "COMP");
    cr_assert(scanner.tokens.back().value == ">");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_comparison_operators_3)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(comparison_analyzer("==", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "COMP");
    cr_assert(scanner.tokens.back().value == "==");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_comparison_operators_4)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(comparison_analyzer("!=", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "COMP");
    cr_assert(scanner.tokens.back().value == "!=");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_comparison_operators_5)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(comparison_analyzer("<=", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "COMP");
    cr_assert(scanner.tokens.back().value == "<=");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_comparison_operators_6)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(comparison_analyzer(">=", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "COMP");
    cr_assert(scanner.tokens.back().value == ">=");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_terminating_symbol)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(semi_analyzer(";", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "SEMI");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_area_scope_symbols_1)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(brace_analyzer("{", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "LBRACE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_area_scope_symbols_2)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(brace_analyzer("}", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "RBRACE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_function_symbols_1)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(paren_analyzer("(", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "LPAREN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_function_symbols_2)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(paren_analyzer(")", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "RPAREN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_separation_symbol)
{
    Scanner scanner;
    std::size_t index = 0;

    cr_assert(comma_analyzer(",", index, scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "COMMA");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}
