#include "../headers/utils.hpp"
#include "../headers/syntax_analyzer.hpp"
#include "../headers/lexical_analyzer.hpp"

/**
 * @brief This function initialize the syntaxAnalyzer struct LR parsing table and SLR grammar
 *
 * @param syntaxAnalyzer the syntaxAnalyzer struct containing LR parsing table and SLR grammar
 */
void initialize(syntaxAnalyzer &syntaxAnalyzer)
{
    // This array defines the SLR grammar
    grammarElement tmpArray[] = {
        {{"CODE"}, "CODE'"},
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

    // This line resizes the SLR grammar vector of the syntaxAnalyzer struct
    syntaxAnalyzer.slrGrammar.resize(27);

    // This loop sets the SLR grammar element in the SLR grammar vector of the syntaxAnalyzer struct
    for (int i = 0; i < 27; i++) {
        syntaxAnalyzer.slrGrammar[i] = tmpArray[i];
    }

    // Here we set the LR parsing table elements
    // Action type can be ACTION::SWAP, ACTION::REPLACE, ACTION::GOTO, ACTION::SWAP
    syntaxAnalyzer.lrTable[0]["vtype"] = actionState{ ACTION::SWAP, 4 };
    syntaxAnalyzer.lrTable[0]["$"] = actionState{ ACTION::REPLACE, 3 };
    syntaxAnalyzer.lrTable[0]["CODE"] = actionState{ ACTION::GOTO, 1 };
    syntaxAnalyzer.lrTable[0]["VDECL"] = actionState{ ACTION::GOTO, 2 };
    syntaxAnalyzer.lrTable[0]["FDECL"] = actionState{ ACTION::GOTO, 3 };
    syntaxAnalyzer.lrTable[1]["$"] = actionState{ ACTION::ACC, 0 };
    syntaxAnalyzer.lrTable[2]["vtype"] = actionState{ ACTION::SWAP, 4 };
    syntaxAnalyzer.lrTable[2]["$"] = actionState{ ACTION::REPLACE, 3 };
    syntaxAnalyzer.lrTable[2]["CODE"] = actionState{ ACTION::GOTO, 5 };
    syntaxAnalyzer.lrTable[2]["VDECL"] = actionState{ ACTION::GOTO, 2 };
    syntaxAnalyzer.lrTable[2]["FDECL"] = actionState{ ACTION::GOTO, 3 };
    syntaxAnalyzer.lrTable[3]["vtype"] = actionState{ ACTION::SWAP, 4 };
    syntaxAnalyzer.lrTable[3]["$"] = actionState{ ACTION::REPLACE, 3 };
    syntaxAnalyzer.lrTable[3]["CODE"] = actionState{ ACTION::GOTO, 6 };
    syntaxAnalyzer.lrTable[3]["VDECL"] = actionState{ ACTION::GOTO, 2 };
    syntaxAnalyzer.lrTable[3]["FDECL"] = actionState{ ACTION::GOTO, 3 };
    syntaxAnalyzer.lrTable[4]["id"] = actionState{ ACTION::SWAP, 7 };
    syntaxAnalyzer.lrTable[5]["$"] = actionState{ ACTION::REPLACE, 1 };
    syntaxAnalyzer.lrTable[6]["$"] = actionState{ ACTION::REPLACE, 2 };
    syntaxAnalyzer.lrTable[7]["semi"] = actionState{ ACTION::SWAP, 8 };
    syntaxAnalyzer.lrTable[7]["lparen"] = actionState{ ACTION::SWAP, 9 };
    syntaxAnalyzer.lrTable[8]["vtype"] = actionState{ ACTION::REPLACE, 4 };
    syntaxAnalyzer.lrTable[8]["id"] = actionState{ ACTION::REPLACE, 4 };
    syntaxAnalyzer.lrTable[8]["rbrace"] = actionState{ ACTION::REPLACE, 4 };
    syntaxAnalyzer.lrTable[8]["if"] = actionState{ ACTION::REPLACE, 4 };
    syntaxAnalyzer.lrTable[8]["while"] = actionState{ ACTION::REPLACE, 4 };
    syntaxAnalyzer.lrTable[8]["return"] = actionState{ ACTION::REPLACE, 4 };
    syntaxAnalyzer.lrTable[8]["$"] = actionState{ ACTION::REPLACE, 4 };
    syntaxAnalyzer.lrTable[9]["vtype"] = actionState{ ACTION::SWAP, 11 };
    syntaxAnalyzer.lrTable[9]["rparen"] = actionState{ ACTION::REPLACE, 7 };
    syntaxAnalyzer.lrTable[9]["ARG"] = actionState{ ACTION::GOTO, 10 };
    syntaxAnalyzer.lrTable[10]["rparen"] = actionState{ ACTION::SWAP, 12 };
    syntaxAnalyzer.lrTable[11]["id"] = actionState{ ACTION::SWAP, 13 };
    syntaxAnalyzer.lrTable[12]["lbrace"] = actionState{ ACTION::SWAP, 14 };
    syntaxAnalyzer.lrTable[13]["rparen"] = actionState{ ACTION::REPLACE, 9 };
    syntaxAnalyzer.lrTable[13]["comma"] = actionState{ ACTION::SWAP, 16 };
    syntaxAnalyzer.lrTable[13]["MOREARGS"] = actionState{ ACTION::GOTO, 15 };
    syntaxAnalyzer.lrTable[14]["vtype"] = actionState{ ACTION::SWAP, 23 };
    syntaxAnalyzer.lrTable[14]["id"] = actionState{ ACTION::SWAP, 20 };
    syntaxAnalyzer.lrTable[14]["rbrace"] = actionState{ ACTION::REPLACE, 11 };
    syntaxAnalyzer.lrTable[14]["if"] = actionState{ ACTION::SWAP, 21 };
    syntaxAnalyzer.lrTable[14]["while"] = actionState{ ACTION::SWAP, 22 };
    syntaxAnalyzer.lrTable[14]["return"] = actionState{ ACTION::REPLACE, 11 };
    syntaxAnalyzer.lrTable[14]["VDECL"] = actionState{ ACTION::GOTO, 19 };
    syntaxAnalyzer.lrTable[14]["BLOCK"] = actionState{ ACTION::GOTO, 17 };
    syntaxAnalyzer.lrTable[14]["STMT"] = actionState{ ACTION::GOTO, 18 };
    syntaxAnalyzer.lrTable[15]["rparen"] = actionState{ ACTION::REPLACE, 6 };
    syntaxAnalyzer.lrTable[16]["vtype"] = actionState{ ACTION::SWAP, 24 };
    syntaxAnalyzer.lrTable[17]["return"] = actionState{ ACTION::SWAP, 26 };
    syntaxAnalyzer.lrTable[17]["RETURN"] = actionState{ ACTION::GOTO, 25 };
    syntaxAnalyzer.lrTable[18]["vtype"] = actionState{ ACTION::SWAP, 23 };
    syntaxAnalyzer.lrTable[18]["id"] = actionState{ ACTION::SWAP, 20 };
    syntaxAnalyzer.lrTable[18]["rbrace"] = actionState{ ACTION::REPLACE, 11 };
    syntaxAnalyzer.lrTable[18]["if"] = actionState{ ACTION::SWAP, 21 };
    syntaxAnalyzer.lrTable[18]["while"] = actionState{ ACTION::SWAP, 22 };
    syntaxAnalyzer.lrTable[18]["return"] = actionState{ ACTION::REPLACE, 11 };
    syntaxAnalyzer.lrTable[18]["VDECL"] = actionState{ ACTION::GOTO, 19 };
    syntaxAnalyzer.lrTable[18]["BLOCK"] = actionState{ ACTION::GOTO, 27 };
    syntaxAnalyzer.lrTable[18]["STMT"] = actionState{ ACTION::GOTO, 18 };
    syntaxAnalyzer.lrTable[19]["vtype"] = actionState{ ACTION::REPLACE, 12 };
    syntaxAnalyzer.lrTable[19]["id"] = actionState{ ACTION::REPLACE, 12 };
    syntaxAnalyzer.lrTable[19]["rbrace"] = actionState{ ACTION::REPLACE, 12 };
    syntaxAnalyzer.lrTable[19]["if"] = actionState{ ACTION::REPLACE, 12 };
    syntaxAnalyzer.lrTable[19]["while"] = actionState{ ACTION::REPLACE, 12 };
    syntaxAnalyzer.lrTable[19]["return"] = actionState{ ACTION::REPLACE, 12 };
    syntaxAnalyzer.lrTable[20]["assign"] = actionState{ ACTION::SWAP, 28 };
    syntaxAnalyzer.lrTable[21]["lparen"] = actionState{ ACTION::SWAP, 29 };
    syntaxAnalyzer.lrTable[22]["lparen"] = actionState{ ACTION::SWAP, 30 };
    syntaxAnalyzer.lrTable[23]["id"] = actionState{ ACTION::SWAP, 31 };
    syntaxAnalyzer.lrTable[24]["id"] = actionState{ ACTION::SWAP, 32 };
    syntaxAnalyzer.lrTable[25]["rbrace"] = actionState{ ACTION::SWAP, 33 };
    syntaxAnalyzer.lrTable[26]["id"] = actionState{ ACTION::SWAP, 36 };
    syntaxAnalyzer.lrTable[26]["lparen"] = actionState{ ACTION::SWAP, 35 };
    syntaxAnalyzer.lrTable[26]["num"] = actionState{ ACTION::SWAP, 37 };
    syntaxAnalyzer.lrTable[26]["FACTOR"] = actionState{ ACTION::GOTO, 34 };
    syntaxAnalyzer.lrTable[27]["rbrace"] = actionState{ ACTION::REPLACE, 10 };
    syntaxAnalyzer.lrTable[27]["return"] = actionState{ ACTION::REPLACE, 10 };
    syntaxAnalyzer.lrTable[28]["id"] = actionState{ ACTION::SWAP, 36 };
    syntaxAnalyzer.lrTable[28]["lparen"] = actionState{ ACTION::SWAP, 35 };
    syntaxAnalyzer.lrTable[28]["literal"] = actionState{ ACTION::SWAP, 40 };
    syntaxAnalyzer.lrTable[28]["num"] = actionState{ ACTION::SWAP, 37 };
    syntaxAnalyzer.lrTable[28]["RHS"] = actionState{ ACTION::GOTO, 38 };
    syntaxAnalyzer.lrTable[28]["EXPR"] = actionState{ ACTION::GOTO, 39 };
    syntaxAnalyzer.lrTable[28]["TERM"] = actionState{ ACTION::GOTO, 41 };
    syntaxAnalyzer.lrTable[28]["FACTOR"] = actionState{ ACTION::GOTO, 42 };
    syntaxAnalyzer.lrTable[29]["id"] = actionState{ ACTION::SWAP, 36 };
    syntaxAnalyzer.lrTable[29]["lparen"] = actionState{ ACTION::SWAP, 35 };
    syntaxAnalyzer.lrTable[29]["num"] = actionState{ ACTION::SWAP, 37 };
    syntaxAnalyzer.lrTable[29]["FACTOR"] = actionState{ ACTION::GOTO, 44 };
    syntaxAnalyzer.lrTable[29]["COND"] = actionState{ ACTION::GOTO, 43 };
    syntaxAnalyzer.lrTable[30]["id"] = actionState{ ACTION::SWAP, 36 };
    syntaxAnalyzer.lrTable[30]["lparen"] = actionState{ ACTION::SWAP, 35 };
    syntaxAnalyzer.lrTable[30]["num"] = actionState{ ACTION::SWAP, 37 };
    syntaxAnalyzer.lrTable[30]["FACTOR"] = actionState{ ACTION::GOTO, 44 };
    syntaxAnalyzer.lrTable[30]["COND"] = actionState{ ACTION::GOTO, 45 };
    syntaxAnalyzer.lrTable[31]["semi"] = actionState{ ACTION::SWAP, 8 };
    syntaxAnalyzer.lrTable[32]["rparen"] = actionState{ ACTION::REPLACE, 9 };
    syntaxAnalyzer.lrTable[32]["comma"] = actionState{ ACTION::SWAP, 16 };
    syntaxAnalyzer.lrTable[32]["MOREARGS"] = actionState{ ACTION::GOTO, 46 };
    syntaxAnalyzer.lrTable[33]["vtype"] = actionState{ ACTION::REPLACE, 5 };
    syntaxAnalyzer.lrTable[33]["$"] = actionState{ ACTION::REPLACE, 5 };
    syntaxAnalyzer.lrTable[34]["semi"] = actionState{ ACTION::SWAP, 47 };
    syntaxAnalyzer.lrTable[35]["id"] = actionState{ ACTION::SWAP, 36 };
    syntaxAnalyzer.lrTable[35]["lparen"] = actionState{ ACTION::SWAP, 35 };
    syntaxAnalyzer.lrTable[35]["num"] = actionState{ ACTION::SWAP, 37 };
    syntaxAnalyzer.lrTable[35]["EXPR"] = actionState{ ACTION::GOTO, 48 };
    syntaxAnalyzer.lrTable[35]["TERM"] = actionState{ ACTION::GOTO, 41 };
    syntaxAnalyzer.lrTable[35]["FACTOR"] = actionState{ ACTION::GOTO, 42 };
    syntaxAnalyzer.lrTable[36]["semi"] = actionState{ ACTION::REPLACE, 23 };
    syntaxAnalyzer.lrTable[36]["rparen"] = actionState{ ACTION::REPLACE, 23 };
    syntaxAnalyzer.lrTable[36]["addsub"] = actionState{ ACTION::REPLACE, 23 };
    syntaxAnalyzer.lrTable[36]["multdiv"] = actionState{ ACTION::REPLACE, 23 };
    syntaxAnalyzer.lrTable[36]["comp"] = actionState{ ACTION::REPLACE, 23 };
    syntaxAnalyzer.lrTable[37]["semi"] = actionState{ ACTION::REPLACE, 24 };
    syntaxAnalyzer.lrTable[37]["rparen"] = actionState{ ACTION::REPLACE, 24 };
    syntaxAnalyzer.lrTable[37]["addsub"] = actionState{ ACTION::REPLACE, 24 };
    syntaxAnalyzer.lrTable[37]["multdiv"] = actionState{ ACTION::REPLACE, 24 };
    syntaxAnalyzer.lrTable[37]["comp"] = actionState{ ACTION::REPLACE, 24 };
    syntaxAnalyzer.lrTable[38]["semi"] = actionState{ ACTION::SWAP, 49 };
    syntaxAnalyzer.lrTable[39]["semi"] = actionState{ ACTION::REPLACE, 16 };
    syntaxAnalyzer.lrTable[40]["semi"] = actionState{ ACTION::REPLACE, 17 };
    syntaxAnalyzer.lrTable[41]["semi"] = actionState{ ACTION::REPLACE, 19 };
    syntaxAnalyzer.lrTable[41]["rparen"] = actionState{ ACTION::REPLACE, 19 };
    syntaxAnalyzer.lrTable[41]["addsub"] = actionState{ ACTION::SWAP, 50 };
    syntaxAnalyzer.lrTable[42]["semi"] = actionState{ ACTION::REPLACE, 21 };
    syntaxAnalyzer.lrTable[42]["rparen"] = actionState{ ACTION::REPLACE, 21 };
    syntaxAnalyzer.lrTable[42]["addsub"] = actionState{ ACTION::REPLACE, 21 };
    syntaxAnalyzer.lrTable[42]["multdiv"] = actionState{ ACTION::SWAP, 51 };
    syntaxAnalyzer.lrTable[43]["rparen"] = actionState{ ACTION::SWAP, 52 };
    syntaxAnalyzer.lrTable[44]["comp"] = actionState{ ACTION::SWAP, 53 };
    syntaxAnalyzer.lrTable[45]["rparen"] = actionState{ ACTION::SWAP, 54 };
    syntaxAnalyzer.lrTable[46]["rparen"] = actionState{ ACTION::REPLACE, 8 };
    syntaxAnalyzer.lrTable[47]["rbrace"] = actionState{ ACTION::REPLACE, 26 };
    syntaxAnalyzer.lrTable[48]["rparen"] = actionState{ ACTION::SWAP, 55 };
    syntaxAnalyzer.lrTable[49]["vtype"] = actionState{ ACTION::REPLACE, 13 };
    syntaxAnalyzer.lrTable[49]["id"] = actionState{ ACTION::REPLACE, 13 };
    syntaxAnalyzer.lrTable[49]["rbrace"] = actionState{ ACTION::REPLACE, 13 };
    syntaxAnalyzer.lrTable[49]["if"] = actionState{ ACTION::REPLACE, 13 };
    syntaxAnalyzer.lrTable[49]["while"] = actionState{ ACTION::REPLACE, 13 };
    syntaxAnalyzer.lrTable[49]["return"] = actionState{ ACTION::REPLACE, 13 };
    syntaxAnalyzer.lrTable[50]["id"] = actionState{ ACTION::SWAP, 36 };
    syntaxAnalyzer.lrTable[50]["lparen"] = actionState{ ACTION::SWAP, 35 };
    syntaxAnalyzer.lrTable[50]["num"] = actionState{ ACTION::SWAP, 37 };
    syntaxAnalyzer.lrTable[50]["EXPR"] = actionState{ ACTION::GOTO, 56 };
    syntaxAnalyzer.lrTable[50]["TERM"] = actionState{ ACTION::GOTO, 41 };
    syntaxAnalyzer.lrTable[50]["FACTOR"] = actionState{ ACTION::GOTO, 42 };
    syntaxAnalyzer.lrTable[51]["id"] = actionState{ ACTION::SWAP, 36 };
    syntaxAnalyzer.lrTable[51]["lparen"] = actionState{ ACTION::SWAP, 35 };
    syntaxAnalyzer.lrTable[51]["num"] = actionState{ ACTION::SWAP, 37 };
    syntaxAnalyzer.lrTable[51]["TERM"] = actionState{ ACTION::GOTO, 57 };
    syntaxAnalyzer.lrTable[51]["FACTOR"] = actionState{ ACTION::GOTO, 42 };
    syntaxAnalyzer.lrTable[52]["lbrace"] = actionState{ ACTION::SWAP, 58 };
    syntaxAnalyzer.lrTable[53]["id"] = actionState{ ACTION::SWAP, 36 };
    syntaxAnalyzer.lrTable[53]["lparen"] = actionState{ ACTION::SWAP, 35 };
    syntaxAnalyzer.lrTable[53]["num"] = actionState{ ACTION::SWAP, 37 };
    syntaxAnalyzer.lrTable[53]["FACTOR"] = actionState{ ACTION::GOTO, 59 };
    syntaxAnalyzer.lrTable[54]["lbrace"] = actionState{ ACTION::SWAP, 60 };
    syntaxAnalyzer.lrTable[55]["semi"] = actionState{ ACTION::REPLACE, 22 };
    syntaxAnalyzer.lrTable[55]["rparen"] = actionState{ ACTION::REPLACE, 22 };
    syntaxAnalyzer.lrTable[55]["addsub"] = actionState{ ACTION::REPLACE, 22 };
    syntaxAnalyzer.lrTable[55]["multdiv"] = actionState{ ACTION::REPLACE, 22 };
    syntaxAnalyzer.lrTable[55]["comp"] = actionState{ ACTION::REPLACE, 22 };
    syntaxAnalyzer.lrTable[56]["semi"] = actionState{ ACTION::REPLACE, 18 };
    syntaxAnalyzer.lrTable[56]["rparen"] = actionState{ ACTION::REPLACE, 18 };
    syntaxAnalyzer.lrTable[57]["semi"] = actionState{ ACTION::REPLACE, 20 };
    syntaxAnalyzer.lrTable[57]["rparen"] = actionState{ ACTION::REPLACE, 20 };
    syntaxAnalyzer.lrTable[57]["addsub"] = actionState{ ACTION::REPLACE, 20 };
    syntaxAnalyzer.lrTable[58]["vtype"] = actionState{ ACTION::SWAP, 23 };
    syntaxAnalyzer.lrTable[58]["id"] = actionState{ ACTION::SWAP, 20 };
    syntaxAnalyzer.lrTable[58]["rbrace"] = actionState{ ACTION::REPLACE, 11 };
    syntaxAnalyzer.lrTable[58]["if"] = actionState{ ACTION::SWAP, 21 };
    syntaxAnalyzer.lrTable[58]["while"] = actionState{ ACTION::SWAP, 22 };
    syntaxAnalyzer.lrTable[58]["return"] = actionState{ ACTION::REPLACE, 11 };
    syntaxAnalyzer.lrTable[58]["VDECL"] = actionState{ ACTION::GOTO, 19 };
    syntaxAnalyzer.lrTable[58]["BLOCK"] = actionState{ ACTION::GOTO, 61 };
    syntaxAnalyzer.lrTable[58]["STMT"] = actionState{ ACTION::GOTO, 18 };
    syntaxAnalyzer.lrTable[59]["rparen"] = actionState{ ACTION::REPLACE, 25 };
    syntaxAnalyzer.lrTable[60]["vtype"] = actionState{ ACTION::SWAP, 23 };
    syntaxAnalyzer.lrTable[60]["id"] = actionState{ ACTION::SWAP, 20 };
    syntaxAnalyzer.lrTable[60]["rbrace"] = actionState{ ACTION::REPLACE, 11 };
    syntaxAnalyzer.lrTable[60]["if"] = actionState{ ACTION::SWAP, 21 };
    syntaxAnalyzer.lrTable[60]["while"] = actionState{ ACTION::SWAP, 22 };
    syntaxAnalyzer.lrTable[60]["return"] = actionState{ ACTION::REPLACE, 11 };
    syntaxAnalyzer.lrTable[60]["VDECL"] = actionState{ ACTION::GOTO, 19 };
    syntaxAnalyzer.lrTable[60]["BLOCK"] = actionState{ ACTION::GOTO, 62 };
    syntaxAnalyzer.lrTable[60]["STMT"] = actionState{ ACTION::GOTO, 18 };
    syntaxAnalyzer.lrTable[61]["rbrace"] = actionState{ ACTION::SWAP, 63 };
    syntaxAnalyzer.lrTable[62]["rbrace"] = actionState{ ACTION::SWAP, 64 };
    syntaxAnalyzer.lrTable[63]["else"] = actionState{ ACTION::SWAP, 65 };
    syntaxAnalyzer.lrTable[64]["vtype"] = actionState{ ACTION::REPLACE, 15 };
    syntaxAnalyzer.lrTable[64]["id"] = actionState{ ACTION::REPLACE, 15 };
    syntaxAnalyzer.lrTable[64]["rbrace"] = actionState{ ACTION::REPLACE, 15 };
    syntaxAnalyzer.lrTable[64]["if"] = actionState{ ACTION::REPLACE, 15 };
    syntaxAnalyzer.lrTable[64]["while"] = actionState{ ACTION::REPLACE, 15 };
    syntaxAnalyzer.lrTable[64]["return"] = actionState{ ACTION::REPLACE, 15 };
    syntaxAnalyzer.lrTable[65]["lbrace"] = actionState{ ACTION::SWAP, 66 };
    syntaxAnalyzer.lrTable[66]["vtype"] = actionState{ ACTION::SWAP, 23 };
    syntaxAnalyzer.lrTable[66]["id"] = actionState{ ACTION::SWAP, 20 };
    syntaxAnalyzer.lrTable[66]["rbrace"] = actionState{ ACTION::REPLACE, 11 };
    syntaxAnalyzer.lrTable[66]["if"] = actionState{ ACTION::SWAP, 21 };
    syntaxAnalyzer.lrTable[66]["while"] = actionState{ ACTION::SWAP, 22 };
    syntaxAnalyzer.lrTable[66]["return"] = actionState{ ACTION::REPLACE, 11 };
    syntaxAnalyzer.lrTable[66]["VDECL"] = actionState{ ACTION::GOTO, 19 };
    syntaxAnalyzer.lrTable[66]["BLOCK"] = actionState{ ACTION::GOTO, 67 };
    syntaxAnalyzer.lrTable[66]["STMT"] = actionState{ ACTION::GOTO, 18 };
    syntaxAnalyzer.lrTable[67]["rbrace"] = actionState{ ACTION::SWAP, 68 };
    syntaxAnalyzer.lrTable[68]["vtype"] = actionState{ ACTION::REPLACE, 14 };
    syntaxAnalyzer.lrTable[68]["id"] = actionState{ ACTION::REPLACE, 14 };
    syntaxAnalyzer.lrTable[68]["rbrace"] = actionState{ ACTION::REPLACE, 14 };
    syntaxAnalyzer.lrTable[68]["if"] = actionState{ ACTION::REPLACE, 14 };
    syntaxAnalyzer.lrTable[68]["while"] = actionState{ ACTION::REPLACE, 14 };
    syntaxAnalyzer.lrTable[68]["return"] = actionState{ ACTION::REPLACE, 14 };
}

/**
 * @brief This function is responsible for the syntax analysis
 *
 * @param scanner the result of the lexical analyzer
 */
void syntax_analyzer(Scanner scanner)
{
    syntaxAnalyzer syntaxAnalyzer;

    // syntaxAnalyzer struct is initialized in this function
    initialize(syntaxAnalyzer);

    // $ symbol is added to the scanned tokens and state 0 is pushed in the state stack
    scanner.tokens.push_back({ "$", "", scanner.lastColumnIndex, scanner.lineIndex });
    syntaxAnalyzer.stateStack.push_back(0);

    // Main parsing loop
    while (true) {
        // Get first token name and last state from state stack
        std::string tokenName = str_transform(scanner.tokens[0].name, std::tolower);
        int currentState = syntaxAnalyzer.stateStack.back();
        actionState currentAction = {};

        // If LR parsing table element does not exist then SyntaxErrorException is thrown
        if (syntaxAnalyzer.lrTable[currentState].find(tokenName) == syntaxAnalyzer.lrTable[currentState].end())
            throw SyntaxErrorException(scanner.tokens[0].lineIndex, scanner.tokens[0].columnIndex);

        // Get LR parsing table action
        currentAction = syntaxAnalyzer.lrTable[currentState][tokenName];

        // Checking action type
        switch (currentAction.actionType) {
            // If action is ACTION::REPLACE
            case ACTION::REPLACE:
            {
                // Get appropriate SLR grammar element from action index
                grammarElement element = syntaxAnalyzer.slrGrammar[currentAction.index];

                // Check if first SLR grammar list element is not ε ("" in our case)
                if (element.listEl[0] != "") {
                    // Remove last elements from state stack and non-terminal/terminal stack
                    // for each element in SLR grammar list element
                    for (int i = 0; i < element.listEl.size(); i++) {
                        syntaxAnalyzer.nttStack.pop_back();
                        syntaxAnalyzer.stateStack.pop_back();
                    }
                }

                // Add SLR grammer element non-terminal to non-terminal/terminal stack
                // Then get new current state from last state stack element
                // Then find GOTO index in LR parsing table and add it to state stack
                syntaxAnalyzer.nttStack.push_back(element.type);
                currentState = syntaxAnalyzer.stateStack.back();
                syntaxAnalyzer.stateStack.push_back(syntaxAnalyzer.lrTable[currentState][element.type].index);
                break;
            }
            // If action is ACTION::SWAP
            case ACTION::SWAP:
                // Add action index in state stack
                // Then add token name to non-terminal/terminal stack
                // Then remove first token of the token list
                syntaxAnalyzer.stateStack.push_back(currentAction.index);
                syntaxAnalyzer.nttStack.push_back(tokenName);
                scanner.tokens.erase(scanner.tokens.begin());
                break;
            // ACTION::GOTO cannot occured as it is handled in ACTION::REPLACE
            // If action is ACTION::ACC then the program structure is valid
            case ACTION::GOTO:
            case ACTION::ACC:
            default:
                return;
        }
    }
}