#include <criterion/criterion.h>

#include "../headers/lexical_analyzer.hpp"

Test(specific_analyzer_test, test_valid_vtype)
{
    Scanner scanner;

    cr_assert(vtype_analyzer("int", scanner) == true);
    cr_assert(vtype_analyzer("INT", scanner) == true);
    cr_assert(vtype_analyzer("char", scanner) == true);
    cr_assert(vtype_analyzer("CHAR", scanner) == true);

    cr_assert(scanner.tokens.size() == 4);

    cr_assert(scanner.tokens.back().name == "VTYPE");
    cr_assert(scanner.tokens.back().value == "char");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "VTYPE");
    cr_assert(scanner.tokens.back().value == "char");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "VTYPE");
    cr_assert(scanner.tokens.back().value == "int");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "VTYPE");
    cr_assert(scanner.tokens.back().value == "int");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_integer)
{
    Scanner scanner;

    cr_assert(integer_analyzer("0", scanner) == true);
    cr_assert(integer_analyzer("-1", scanner) == true);
    cr_assert(integer_analyzer("10", scanner) == true);
    cr_assert(integer_analyzer("999", scanner) == true);

    cr_assert(scanner.tokens.size() == 4);

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "999");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "10");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "-1");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "0");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_string)
{
    Scanner scanner;

    cr_assert(string_analyzer("\"Hello world\"", scanner) == true);
    cr_assert(string_analyzer("\"My student id is 12345678\"", scanner) == true);

    cr_assert(scanner.tokens.size() == 2);

    cr_assert(scanner.tokens.back().name == "STRING");
    cr_assert(scanner.tokens.back().value == "My student id is 12345678");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "STRING");
    cr_assert(scanner.tokens.back().value == "Hello world");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_identifier)
{
    Scanner scanner;

    cr_assert(identifier_analyzer("i", scanner) == true);
    cr_assert(identifier_analyzer("j", scanner) == true);
    cr_assert(identifier_analyzer("k", scanner) == true);
    cr_assert(identifier_analyzer("abc", scanner) == true);
    cr_assert(identifier_analyzer("ab123", scanner) == true);
    cr_assert(identifier_analyzer("func1", scanner) == true);

    cr_assert(scanner.tokens.size() == 6);

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "func1");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "ab123");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "abc");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "k");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "j");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "i");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_keyword)
{
    Scanner scanner;

    cr_assert(keyword_analyzer("if", scanner) == true);
    cr_assert(keyword_analyzer("IF", scanner) == true);
    cr_assert(keyword_analyzer("else", scanner) == true);
    cr_assert(keyword_analyzer("ELSE", scanner) == true);
    cr_assert(keyword_analyzer("while", scanner) == true);
    cr_assert(keyword_analyzer("WHILE", scanner) == true);
    cr_assert(keyword_analyzer("return", scanner) == true);
    cr_assert(keyword_analyzer("RETURN", scanner) == true);

    cr_assert(scanner.tokens.size() == 8);

    cr_assert(scanner.tokens.back().name == "RETURN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "RETURN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "WHILE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "WHILE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ELSE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ELSE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "IF");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "IF");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_arithmetic_operators)
{
    Scanner scanner;

    cr_assert(arithmetic_analyzer("+", scanner) == true);
    cr_assert(arithmetic_analyzer("-", scanner) == true);
    cr_assert(arithmetic_analyzer("*", scanner) == true);
    cr_assert(arithmetic_analyzer("/", scanner) == true);

    cr_assert(scanner.tokens.size() == 4);

    cr_assert(scanner.tokens.back().name == "OP");
    cr_assert(scanner.tokens.back().value == "/");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "OP");
    cr_assert(scanner.tokens.back().value == "*");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "OP");
    cr_assert(scanner.tokens.back().value == "-");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "OP");
    cr_assert(scanner.tokens.back().value == "+");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_assignment_operators)
{
    Scanner scanner;

    cr_assert(assignment_analyzer("=", scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "ASSIGN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_comparison_operators)
{
    Scanner scanner;

    cr_assert(comparison_analyzer("<", scanner) == true);
    cr_assert(comparison_analyzer(">", scanner) == true);
    cr_assert(comparison_analyzer("==", scanner) == true);
    cr_assert(comparison_analyzer("!=", scanner) == true);
    cr_assert(comparison_analyzer("<=", scanner) == true);
    cr_assert(comparison_analyzer(">=", scanner) == true);

    cr_assert(scanner.tokens.size() == 6);

    cr_assert(scanner.tokens.back().name == "COMP");
    cr_assert(scanner.tokens.back().value == ">=");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "COMP");
    cr_assert(scanner.tokens.back().value == "<=");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "COMP");
    cr_assert(scanner.tokens.back().value == "!=");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "COMP");
    cr_assert(scanner.tokens.back().value == "==");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "COMP");
    cr_assert(scanner.tokens.back().value == ">");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "COMP");
    cr_assert(scanner.tokens.back().value == "<");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_terminating_symbol)
{
    Scanner scanner;

    cr_assert(semi_analyzer(";", scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "SEMI");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_area_scope_symbols)
{
    Scanner scanner;

    cr_assert(brace_analyzer("{", scanner) == true);
    cr_assert(brace_analyzer("}", scanner) == true);

    cr_assert(scanner.tokens.size() == 2);

    cr_assert(scanner.tokens.back().name == "RBRACE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "LBRACE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_function_symbols)
{
    Scanner scanner;

    cr_assert(paren_analyzer("(", scanner) == true);
    cr_assert(paren_analyzer(")", scanner) == true);

    cr_assert(scanner.tokens.size() == 2);

    cr_assert(scanner.tokens.back().name == "RPAREN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "LPAREN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(specific_analyzer_test, test_valid_separation_symbol)
{
    Scanner scanner;

    cr_assert(comma_analyzer(",", scanner) == true);

    cr_assert(scanner.tokens.size() == 1);

    cr_assert(scanner.tokens.back().name == "COMMA");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}
