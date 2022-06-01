#include "../headers/syntax_analyzer.hpp"
#include "../headers/lexical_analyzer.hpp"

void initialize(syntaxAnalyzer &syntaxAnalyzer) {
    grammarElement tmpArray[] = {
        {{"VDECL", "CODE"}, "CODE"},
        {{"FDECL", "CODE"}, "CODE"},
        {{""}, "CODE"},
        {{"vtype", "id", "semi"}, "VDECL"},
        {{"vtype", "id", "lparen", "ARG", "rparen", "lbrace", "BLOCK", "RETURN", "rbrace"}, "FDECL"},
        {{"vtype", "id", "MOREARGS"}, "ARG"},
        {{""}, "ARG"},
        {{"comma", "vtype", "id", "MOREARGS"}, "MOREARGS"},
        {{""}, "MOREARGS"},
        {{"STMT", "BLOCK"}, "BLOCK"},
        {{""}, "BLOCK"},
        {{"VDECL"}, "STMT"},
        {{"id", "assign", "RHS", "semi"}, "STMT"},
        {{"if", "lparen", "COND", "rparen", "lbrace", "BLOCK", "rbrace", "else", "lbrace", "BLOCK", "rbrace"}, "STMT"},
        {{"while", "lparen", "COND", "rparen", "lbrace", "BLOCK", "rbrace"}, "STMT"},
        {{"EXPR"}, "RHS"},
        {{"literal"}, "RHS"},
        {{"TERM", "addsub", "EXPR"}, "EXPR"},
        {{"TERM"}, "EXPR"},
        {{"FACTOR", "multdiv", "TERM"}, "TERM"},
        {{"FACTOR"}, "TERM"},
        {{"lparen", "EXPR", "rparen"}, "FACTOR"},
        {{"id"}, "FACTOR"},
        {{"num"}, "FACTOR"},
        {{"FACTOR", "comp", "FACTOR"}, "COND"},
        {{"return", "FACTOR", "semi"}, "RETURN"},
    };

    syntaxAnalyzer.slrGrammar.resize(26);

    for (int i = 0; i < 26; i++) {
        syntaxAnalyzer.slrGrammar[i] = tmpArray[i];
    }

    syntaxAnalyzer.lrTable[0]["vtype"] = actionState{ACTION::SWAP, 2};
    syntaxAnalyzer.lrTable[0]["VDECL"] = actionState{ACTION::GOTO, 1};
    syntaxAnalyzer.lrTable[1]["vtype"] = actionState{ACTION::SWAP, 5};
    syntaxAnalyzer.lrTable[1]["$"] = actionState{ACTION::REPLACE, 2};
    syntaxAnalyzer.lrTable[1]["CODE"] = actionState{ACTION::GOTO, 3};
    syntaxAnalyzer.lrTable[1]["VDECL"] = actionState{ACTION::GOTO, 1};
    syntaxAnalyzer.lrTable[1]["FDECL"] = actionState{ACTION::GOTO, 4};
    syntaxAnalyzer.lrTable[2]["id"] = actionState{ACTION::SWAP, 6};
    syntaxAnalyzer.lrTable[3]["$"] = actionState{ACTION::ACC, 0};
    syntaxAnalyzer.lrTable[4]["vtype"] = actionState{ACTION::SWAP, 5};
    syntaxAnalyzer.lrTable[4]["$"] = actionState{ACTION::REPLACE, 2};
    syntaxAnalyzer.lrTable[4]["CODE"] = actionState{ACTION::GOTO, 7};
    syntaxAnalyzer.lrTable[4]["VDECL"] = actionState{ACTION::GOTO, 1};
    syntaxAnalyzer.lrTable[4]["FDECL"] = actionState{ACTION::GOTO, 4};
    syntaxAnalyzer.lrTable[5]["id"] = actionState{ACTION::SWAP, 8};
    syntaxAnalyzer.lrTable[6]["semi"] = actionState{ACTION::SWAP, 9};
    syntaxAnalyzer.lrTable[7]["$"] = actionState{ACTION::REPLACE, 1};
    syntaxAnalyzer.lrTable[8]["semi"] = actionState{ACTION::SWAP, 9};
    syntaxAnalyzer.lrTable[8]["lparen"] = actionState{ACTION::SWAP, 10};
    syntaxAnalyzer.lrTable[9]["vtype"] = actionState{ACTION::REPLACE, 3};
    syntaxAnalyzer.lrTable[9]["id"] = actionState{ACTION::REPLACE, 3};
    syntaxAnalyzer.lrTable[9]["rbrace"] = actionState{ACTION::REPLACE, 3};
    syntaxAnalyzer.lrTable[9]["if"] = actionState{ACTION::REPLACE, 3};
    syntaxAnalyzer.lrTable[9]["while"] = actionState{ACTION::REPLACE, 3};
    syntaxAnalyzer.lrTable[9]["return"] = actionState{ACTION::REPLACE, 3};
    syntaxAnalyzer.lrTable[9]["$"] = actionState{ACTION::REPLACE, 3};
    syntaxAnalyzer.lrTable[10]["vtype"] = actionState{ACTION::SWAP, 12};
    syntaxAnalyzer.lrTable[10]["rparen"] = actionState{ACTION::REPLACE, 6};
    syntaxAnalyzer.lrTable[10]["ARG"] = actionState{ACTION::GOTO, 11};
    syntaxAnalyzer.lrTable[11]["rparen"] = actionState{ACTION::SWAP, 13};
    syntaxAnalyzer.lrTable[12]["id"] = actionState{ACTION::SWAP, 14};
    syntaxAnalyzer.lrTable[13]["lbrace"] = actionState{ACTION::SWAP, 15};
    syntaxAnalyzer.lrTable[14]["rparen"] = actionState{ACTION::REPLACE, 8};
    syntaxAnalyzer.lrTable[14]["comma"] = actionState{ACTION::SWAP, 17};
    syntaxAnalyzer.lrTable[14]["MOREARGS"] = actionState{ACTION::GOTO, 16};
    syntaxAnalyzer.lrTable[15]["vtype"] = actionState{ACTION::SWAP, 2};
    syntaxAnalyzer.lrTable[15]["id"] = actionState{ACTION::SWAP, 21};
    syntaxAnalyzer.lrTable[15]["rbrace"] = actionState{ACTION::REPLACE, 10};
    syntaxAnalyzer.lrTable[15]["if"] = actionState{ACTION::SWAP, 22};
    syntaxAnalyzer.lrTable[15]["while"] = actionState{ACTION::SWAP, 23};
    syntaxAnalyzer.lrTable[15]["return"] = actionState{ACTION::REPLACE, 10};
    syntaxAnalyzer.lrTable[15]["VDECL"] = actionState{ACTION::GOTO, 20};
    syntaxAnalyzer.lrTable[15]["BLOCK"] = actionState{ACTION::GOTO, 18};
    syntaxAnalyzer.lrTable[15]["STMT"] = actionState{ACTION::GOTO, 19};
    syntaxAnalyzer.lrTable[16]["rparen"] = actionState{ACTION::REPLACE, 5};
    syntaxAnalyzer.lrTable[17]["vtype"] = actionState{ACTION::SWAP, 24};
    syntaxAnalyzer.lrTable[18]["return"] = actionState{ACTION::SWAP, 26};
    syntaxAnalyzer.lrTable[18]["RETURN"] = actionState{ACTION::GOTO, 25};
    syntaxAnalyzer.lrTable[19]["vtype"] = actionState{ACTION::SWAP, 2};
    syntaxAnalyzer.lrTable[19]["id"] = actionState{ACTION::SWAP, 21};
    syntaxAnalyzer.lrTable[19]["rbrace"] = actionState{ACTION::REPLACE, 10};
    syntaxAnalyzer.lrTable[19]["if"] = actionState{ACTION::SWAP, 22};
    syntaxAnalyzer.lrTable[19]["while"] = actionState{ACTION::SWAP, 23};
    syntaxAnalyzer.lrTable[19]["return"] = actionState{ACTION::REPLACE, 10};
    syntaxAnalyzer.lrTable[19]["VDECL"] = actionState{ACTION::GOTO, 20};
    syntaxAnalyzer.lrTable[19]["BLOCK"] = actionState{ACTION::GOTO, 27};
    syntaxAnalyzer.lrTable[19]["STMT"] = actionState{ACTION::GOTO, 19};
    syntaxAnalyzer.lrTable[20]["vtype"] = actionState{ACTION::REPLACE, 11};
    syntaxAnalyzer.lrTable[20]["id"] = actionState{ACTION::REPLACE, 11};
    syntaxAnalyzer.lrTable[20]["rbrace"] = actionState{ACTION::REPLACE, 11};
    syntaxAnalyzer.lrTable[20]["if"] = actionState{ACTION::REPLACE, 11};
    syntaxAnalyzer.lrTable[20]["while"] = actionState{ACTION::REPLACE, 11};
    syntaxAnalyzer.lrTable[20]["return"] = actionState{ACTION::REPLACE, 11};
    syntaxAnalyzer.lrTable[21]["assign"] = actionState{ACTION::SWAP, 28};
    syntaxAnalyzer.lrTable[22]["lparen"] = actionState{ACTION::SWAP, 29};
    syntaxAnalyzer.lrTable[23]["lparen"] = actionState{ACTION::SWAP, 30};
    syntaxAnalyzer.lrTable[24]["id"] = actionState{ACTION::SWAP, 31};
    syntaxAnalyzer.lrTable[25]["rbrace"] = actionState{ACTION::SWAP, 32};
    syntaxAnalyzer.lrTable[26]["id"] = actionState{ACTION::SWAP, 35};
    syntaxAnalyzer.lrTable[26]["lparen"] = actionState{ACTION::SWAP, 34};
    syntaxAnalyzer.lrTable[26]["num"] = actionState{ACTION::SWAP, 36};
    syntaxAnalyzer.lrTable[26]["FACTOR"] = actionState{ACTION::GOTO, 33};
    syntaxAnalyzer.lrTable[27]["rbrace"] = actionState{ACTION::REPLACE, 9};
    syntaxAnalyzer.lrTable[27]["return"] = actionState{ACTION::REPLACE, 9};
    syntaxAnalyzer.lrTable[28]["id"] = actionState{ACTION::SWAP, 35};
    syntaxAnalyzer.lrTable[28]["lparen"] = actionState{ACTION::SWAP, 34};
    syntaxAnalyzer.lrTable[28]["literal"] = actionState{ACTION::SWAP, 39};
    syntaxAnalyzer.lrTable[28]["num"] = actionState{ACTION::SWAP, 36};
    syntaxAnalyzer.lrTable[28]["RHS"] = actionState{ACTION::GOTO, 37};
    syntaxAnalyzer.lrTable[28]["EXPR"] = actionState{ACTION::GOTO, 38};
    syntaxAnalyzer.lrTable[28]["TERM"] = actionState{ACTION::GOTO, 40};
    syntaxAnalyzer.lrTable[28]["FACTOR"] = actionState{ACTION::GOTO, 41};
    syntaxAnalyzer.lrTable[29]["id"] = actionState{ACTION::SWAP, 35};
    syntaxAnalyzer.lrTable[29]["lparen"] = actionState{ACTION::SWAP, 34};
    syntaxAnalyzer.lrTable[29]["num"] = actionState{ACTION::SWAP, 36};
    syntaxAnalyzer.lrTable[29]["FACTOR"] = actionState{ACTION::GOTO, 43};
    syntaxAnalyzer.lrTable[29]["COND"] = actionState{ACTION::GOTO, 42};
    syntaxAnalyzer.lrTable[30]["id"] = actionState{ACTION::SWAP, 35};
    syntaxAnalyzer.lrTable[30]["lparen"] = actionState{ACTION::SWAP, 34};
    syntaxAnalyzer.lrTable[30]["num"] = actionState{ACTION::SWAP, 36};
    syntaxAnalyzer.lrTable[30]["FACTOR"] = actionState{ACTION::GOTO, 43};
    syntaxAnalyzer.lrTable[30]["COND"] = actionState{ACTION::GOTO, 44};
    syntaxAnalyzer.lrTable[31]["lparen"] = actionState{ACTION::REPLACE, 8};
    syntaxAnalyzer.lrTable[31]["comma"] = actionState{ACTION::SWAP, 17};
    syntaxAnalyzer.lrTable[31]["MOREARGS"] = actionState{ACTION::GOTO, 45};
    syntaxAnalyzer.lrTable[32]["vtype"] = actionState{ACTION::REPLACE, 4};
    syntaxAnalyzer.lrTable[32]["$"] = actionState{ACTION::REPLACE, 4};
    syntaxAnalyzer.lrTable[33]["semi"] = actionState{ACTION::SWAP, 46};
    syntaxAnalyzer.lrTable[34]["id"] = actionState{ACTION::SWAP, 34};
    syntaxAnalyzer.lrTable[34]["lparen"] = actionState{ACTION::SWAP, 34};
    syntaxAnalyzer.lrTable[34]["num"] = actionState{ACTION::SWAP, 36};
    syntaxAnalyzer.lrTable[34]["EXPR"] = actionState{ACTION::GOTO, 47};
    syntaxAnalyzer.lrTable[34]["TERM"] = actionState{ACTION::GOTO, 40};
    syntaxAnalyzer.lrTable[34]["FACTOR"] = actionState{ACTION::GOTO, 41};
    syntaxAnalyzer.lrTable[35]["semi"] = actionState{ACTION::REPLACE, 22};
    syntaxAnalyzer.lrTable[35]["rparen"] = actionState{ACTION::REPLACE, 22};
    syntaxAnalyzer.lrTable[35]["addsub"] = actionState{ACTION::REPLACE, 22};
    syntaxAnalyzer.lrTable[35]["multdiv"] = actionState{ACTION::REPLACE, 22};
    syntaxAnalyzer.lrTable[35]["comp"] = actionState{ACTION::REPLACE, 22};
    syntaxAnalyzer.lrTable[36]["semi"] = actionState{ACTION::REPLACE, 23};
    syntaxAnalyzer.lrTable[36]["rparen"] = actionState{ACTION::REPLACE, 23};
    syntaxAnalyzer.lrTable[36]["addsub"] = actionState{ACTION::REPLACE, 23};
    syntaxAnalyzer.lrTable[36]["multdiv"] = actionState{ACTION::REPLACE, 23};
    syntaxAnalyzer.lrTable[36]["comp"] = actionState{ACTION::REPLACE, 23};
    syntaxAnalyzer.lrTable[37]["semi"] = actionState{ACTION::SWAP, 48};
    syntaxAnalyzer.lrTable[38]["semi"] = actionState{ACTION::REPLACE, 15};
    syntaxAnalyzer.lrTable[39]["semi"] = actionState{ACTION::REPLACE, 16};
    syntaxAnalyzer.lrTable[40]["semi"] = actionState{ACTION::REPLACE, 18};
    syntaxAnalyzer.lrTable[40]["rparen"] = actionState{ACTION::REPLACE, 18};
    syntaxAnalyzer.lrTable[40]["addsub"] = actionState{ACTION::SWAP, 49};
    syntaxAnalyzer.lrTable[41]["semi"] = actionState{ACTION::REPLACE, 20};
    syntaxAnalyzer.lrTable[41]["rparen"] = actionState{ACTION::REPLACE, 20};
    syntaxAnalyzer.lrTable[41]["addsub"] = actionState{ACTION::REPLACE, 20};
    syntaxAnalyzer.lrTable[41]["multdiv"] = actionState{ACTION::SWAP, 50};
    syntaxAnalyzer.lrTable[42]["rparen"] = actionState{ACTION::SWAP, 51};
    syntaxAnalyzer.lrTable[43]["comp"] = actionState{ACTION::SWAP, 52};
    syntaxAnalyzer.lrTable[45]["rparen"] = actionState{ACTION::REPLACE, 7};
    syntaxAnalyzer.lrTable[46]["rbrace"] = actionState{ACTION::REPLACE, 25};
    syntaxAnalyzer.lrTable[47]["rparen"] = actionState{ACTION::SWAP, 54};
    syntaxAnalyzer.lrTable[48]["vtype"] = actionState{ACTION::REPLACE, 12};
    syntaxAnalyzer.lrTable[48]["id"] = actionState{ACTION::REPLACE, 12};
    syntaxAnalyzer.lrTable[48]["rbrace"] = actionState{ACTION::REPLACE, 12};
    syntaxAnalyzer.lrTable[48]["if"] = actionState{ACTION::REPLACE, 12};
    syntaxAnalyzer.lrTable[48]["while"] = actionState{ACTION::REPLACE, 12};
    syntaxAnalyzer.lrTable[48]["return"] = actionState{ACTION::REPLACE, 12};
    syntaxAnalyzer.lrTable[49]["id"] = actionState{ACTION::SWAP, 35};
    syntaxAnalyzer.lrTable[49]["lparen"] = actionState{ACTION::SWAP, 34};
    syntaxAnalyzer.lrTable[49]["num"] = actionState{ACTION::SWAP, 36};
    syntaxAnalyzer.lrTable[49]["EXPR"] = actionState{ACTION::GOTO, 55};
    syntaxAnalyzer.lrTable[49]["TERM"] = actionState{ACTION::GOTO, 40};
    syntaxAnalyzer.lrTable[49]["FACTOR"] = actionState{ACTION::GOTO, 41};
    syntaxAnalyzer.lrTable[50]["id"] = actionState{ACTION::SWAP, 35};
    syntaxAnalyzer.lrTable[50]["lparen"] = actionState{ACTION::SWAP, 34};
    syntaxAnalyzer.lrTable[50]["num"] = actionState{ACTION::SWAP, 36};
    syntaxAnalyzer.lrTable[50]["TERM"] = actionState{ACTION::GOTO, 56};
    syntaxAnalyzer.lrTable[50]["FACTOR"] = actionState{ACTION::GOTO, 41};
    syntaxAnalyzer.lrTable[51]["lbrace"] = actionState{ACTION::SWAP, 57};
    syntaxAnalyzer.lrTable[52]["id"] = actionState{ACTION::SWAP, 35};
    syntaxAnalyzer.lrTable[52]["lparen"] = actionState{ACTION::SWAP, 34};
    syntaxAnalyzer.lrTable[52]["num"] = actionState{ACTION::SWAP, 36};
    syntaxAnalyzer.lrTable[52]["FACTOR"] = actionState{ACTION::GOTO, 58};
    syntaxAnalyzer.lrTable[53]["lbrace"] = actionState{ACTION::SWAP, 59};
    syntaxAnalyzer.lrTable[54]["semi"] = actionState{ACTION::REPLACE, 21};
    syntaxAnalyzer.lrTable[54]["rparen"] = actionState{ACTION::REPLACE, 21};
    syntaxAnalyzer.lrTable[54]["addsub"] = actionState{ACTION::REPLACE, 21};
    syntaxAnalyzer.lrTable[54]["multdiv"] = actionState{ACTION::REPLACE, 21};
    syntaxAnalyzer.lrTable[54]["comp"] = actionState{ACTION::REPLACE, 21};
    syntaxAnalyzer.lrTable[55]["semi"] = actionState{ACTION::REPLACE, 17};
    syntaxAnalyzer.lrTable[55]["rparen"] = actionState{ACTION::REPLACE, 17};
    syntaxAnalyzer.lrTable[56]["semi"] = actionState{ACTION::REPLACE, 19};
    syntaxAnalyzer.lrTable[56]["rparen"] = actionState{ACTION::REPLACE, 19};
    syntaxAnalyzer.lrTable[56]["addsub"] = actionState{ACTION::REPLACE, 19};
    syntaxAnalyzer.lrTable[57]["vtype"] = actionState{ACTION::SWAP, 2};
    syntaxAnalyzer.lrTable[57]["id"] = actionState{ACTION::SWAP, 21};
    syntaxAnalyzer.lrTable[57]["rbrace"] = actionState{ACTION::REPLACE, 10};
    syntaxAnalyzer.lrTable[57]["if"] = actionState{ACTION::SWAP, 22};
    syntaxAnalyzer.lrTable[57]["while"] = actionState{ACTION::SWAP, 23};
    syntaxAnalyzer.lrTable[57]["return"] = actionState{ACTION::REPLACE, 10};
    syntaxAnalyzer.lrTable[57]["VDECL"] = actionState{ACTION::GOTO, 20};
    syntaxAnalyzer.lrTable[57]["BLOCK"] = actionState{ACTION::GOTO, 60};
    syntaxAnalyzer.lrTable[57]["STMT"] = actionState{ACTION::GOTO, 19};
    syntaxAnalyzer.lrTable[58]["rparen"] = actionState{ACTION::REPLACE, 24};
    syntaxAnalyzer.lrTable[59]["vtype"] = actionState{ACTION::SWAP, 2};
    syntaxAnalyzer.lrTable[59]["id"] = actionState{ACTION::SWAP, 21};
    syntaxAnalyzer.lrTable[59]["rbrace"] = actionState{ACTION::REPLACE, 10};
    syntaxAnalyzer.lrTable[59]["if"] = actionState{ACTION::SWAP, 22};
    syntaxAnalyzer.lrTable[59]["while"] = actionState{ACTION::SWAP, 23};
    syntaxAnalyzer.lrTable[59]["return"] = actionState{ACTION::REPLACE, 10};
    syntaxAnalyzer.lrTable[59]["VDECL"] = actionState{ACTION::GOTO, 20};
    syntaxAnalyzer.lrTable[59]["BLOCK"] = actionState{ACTION::GOTO, 61};
    syntaxAnalyzer.lrTable[59]["STMT"] = actionState{ACTION::GOTO, 19};
    syntaxAnalyzer.lrTable[60]["rbrace"] = actionState{ACTION::SWAP, 62};
    syntaxAnalyzer.lrTable[61]["rbrace"] = actionState{ACTION::SWAP, 63};
    syntaxAnalyzer.lrTable[62]["else"] = actionState{ACTION::SWAP, 64};
    syntaxAnalyzer.lrTable[63]["vtype"] = actionState{ACTION::REPLACE, 14};
    syntaxAnalyzer.lrTable[63]["id"] = actionState{ACTION::REPLACE, 14};
    syntaxAnalyzer.lrTable[63]["rbrace"] = actionState{ACTION::REPLACE, 14};
    syntaxAnalyzer.lrTable[63]["if"] = actionState{ACTION::REPLACE, 14};
    syntaxAnalyzer.lrTable[63]["while"] = actionState{ACTION::REPLACE, 14};
    syntaxAnalyzer.lrTable[63]["return"] = actionState{ACTION::REPLACE, 14};
    syntaxAnalyzer.lrTable[64]["lbrace"] = actionState{ACTION::SWAP, 65};
    syntaxAnalyzer.lrTable[65]["vtype"] = actionState{ACTION::SWAP, 2};
    syntaxAnalyzer.lrTable[65]["id"] = actionState{ACTION::SWAP, 21};
    syntaxAnalyzer.lrTable[65]["rbrace"] = actionState{ACTION::REPLACE, 10};
    syntaxAnalyzer.lrTable[65]["if"] = actionState{ACTION::SWAP, 22};
    syntaxAnalyzer.lrTable[65]["while"] = actionState{ACTION::SWAP, 23};
    syntaxAnalyzer.lrTable[65]["return"] = actionState{ACTION::REPLACE, 10};
    syntaxAnalyzer.lrTable[65]["VDECL"] = actionState{ACTION::GOTO, 20};
    syntaxAnalyzer.lrTable[65]["BLOCK"] = actionState{ACTION::GOTO, 66};
    syntaxAnalyzer.lrTable[65]["STMT"] = actionState{ACTION::GOTO, 19};
    syntaxAnalyzer.lrTable[66]["rbrace"] = actionState{ACTION::SWAP, 67};
    syntaxAnalyzer.lrTable[67]["vtype"] = actionState{ACTION::REPLACE, 13};
    syntaxAnalyzer.lrTable[67]["id"] = actionState{ACTION::REPLACE, 13};
    syntaxAnalyzer.lrTable[67]["rbrace"] = actionState{ACTION::REPLACE, 13};
    syntaxAnalyzer.lrTable[67]["if"] = actionState{ACTION::REPLACE, 13};
    syntaxAnalyzer.lrTable[67]["while"] = actionState{ACTION::REPLACE, 13};
    syntaxAnalyzer.lrTable[67]["return"] = actionState{ACTION::REPLACE, 13};
}

void syntax_analyzer(Scanner scanner) {
    syntaxAnalyzer syntaxAnalyzer;

    initialize(syntaxAnalyzer);
}