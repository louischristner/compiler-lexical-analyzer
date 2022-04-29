#include <criterion/criterion.h>

#include "../headers/lexical_analyzer.hpp"
#include "../headers/exceptions/LexicalErrorException.hpp"

Test(lexical_analyzer_test, test_minus_zero)
{
    Scanner scanner;

    lexical_analyzer("-0", scanner);

    cr_assert(scanner.tokens.size() > 0);

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "0");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "OP");
    cr_assert(scanner.tokens.back().value == "-");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(lexical_analyzer_test, test_int_0_id_abc0)
{
    Scanner scanner;

    lexical_analyzer("0abc0", scanner);

    cr_assert(scanner.tokens.size() > 0);

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "abc0");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "0");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(lexical_analyzer_test, test_int_123_if)
{
    Scanner scanner;

    lexical_analyzer("123if", scanner);

    cr_assert(scanner.tokens.size() > 0);

    cr_assert(scanner.tokens.back().name == "IF");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "123");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(lexical_analyzer_test, test_int_123_id_if0)
{
    Scanner scanner;

    lexical_analyzer("123if0", scanner);

    cr_assert(scanner.tokens.size() > 0);

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "if0");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "123");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(lexical_analyzer_test, test_blank_string)
{
    Scanner scanner;

    lexical_analyzer("\" \"", scanner);

    cr_assert(scanner.tokens.size() > 0);

    cr_assert(scanner.tokens.back().name == "STRING");
    cr_assert(scanner.tokens.back().value == " ");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(lexical_analyzer_test, test_id_a_minus_int_1)
{
    Scanner scanner;

    lexical_analyzer("a-1", scanner);

    cr_assert(scanner.tokens.size() > 0);

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "1");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "OP");
    cr_assert(scanner.tokens.back().value == "-");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "a");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(lexical_analyzer_test, test_id_a_minus_int_minus_1)
{
    Scanner scanner;

    lexical_analyzer("a--1", scanner);

    cr_assert(scanner.tokens.size() > 0);

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "-1");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "OP");
    cr_assert(scanner.tokens.back().value == "-");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "a");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(lexical_analyzer_test, test_id_a_hashtag_if_lexical_error)
{
    Scanner scanner;

    cr_assert_throw(lexical_analyzer("a#if", scanner), LexicalErrorException);
}

Test(lexical_analyzer_test, test_main_func_1)
{
    Scanner scanner;

    lexical_analyzer("int func(int a) { return 0; }", scanner);

    cr_assert(scanner.tokens.size() > 0);

    cr_assert(scanner.tokens.back().name == "RBRACE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "SEMI");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "0");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "RETURN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "LBRACE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "RPAREN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "a");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "VTYPE");
    cr_assert(scanner.tokens.back().value == "int");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "LPAREN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "func");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "VTYPE");
    cr_assert(scanner.tokens.back().value == "int");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}

Test(lexical_analyzer_test, test_main_func_2)
{
    Scanner scanner;

    lexical_analyzer("int main(){char if123=\"1\";int 0a=a+-1;return -0;}", scanner);

    cr_assert(scanner.tokens.size() > 0);

    cr_assert(scanner.tokens.back().name == "RBRACE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "SEMI");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "0");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "OP");
    cr_assert(scanner.tokens.back().value == "-");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "RETURN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "SEMI");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "-1");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "OP");
    cr_assert(scanner.tokens.back().value == "+");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "a");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ASSIGN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "a");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "INTEGER");
    cr_assert(scanner.tokens.back().value == "0");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "VTYPE");
    cr_assert(scanner.tokens.back().value == "int");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "SEMI");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "STRING");
    cr_assert(scanner.tokens.back().value == "1");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ASSIGN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "if123");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "VTYPE");
    cr_assert(scanner.tokens.back().value == "char");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "LBRACE");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "RPAREN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "LPAREN");
    cr_assert(scanner.tokens.back().value == "");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "ID");
    cr_assert(scanner.tokens.back().value == "main");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.back().name == "VTYPE");
    cr_assert(scanner.tokens.back().value == "int");
    scanner.tokens.pop_back();

    cr_assert(scanner.tokens.size() == 0);
}
