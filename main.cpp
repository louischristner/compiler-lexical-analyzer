#include <iostream>
#include <fstream>

#include "headers/lexical_analyzer.hpp"
#include "headers/exceptions/LexicalErrorException.hpp"
#include "headers/exceptions/FileNotFoundException.hpp"

/**
 * @brief Generate the output file from scanner
 *
 * @param scanner scanner containing the lexical analyze result
 * @param filename name of the file
 */
void generate_output_file(Scanner &scanner, const std::string &filename)
{
    std::ofstream outputFile(filename + ".out");

    if (outputFile.is_open()) {
        for (const Token &token : scanner.tokens) {
            if (token.value == "" && token.name != "STRING") {
                outputFile << "<" << token.name << ">\n";
            } else outputFile << "<" << token.name << ", " << token.value << ">\n";
        }

        outputFile.close();
    }
}

/**
 * @brief Generate an error report based on exception
 *
 * @param e lexical error exception
 * @param line line causing error
 * @param filename name of the file
 */
void generate_error_report(LexicalErrorException &e, const std::string &line, const std::string &filename)
{
    std::ofstream outputFile(filename + ".out");

    if (outputFile.is_open()) {
        outputFile << "ERROR: lexical error at line " << e.getLineIndex() << " column " << e.getColumnIndex() << std::endl;
        outputFile << line << std::endl;
        outputFile << std::string(e.getColumnIndex() - 1, ' ') << "^" << std::endl;
        outputFile.close();
    }
}

/**
 * @brief Get the input content object
 *
 * @param filename name of the file
 * @return vector<string> lines of the file
 */
std::vector<std::string> get_input_content(const std::string &filename)
{
    std::string line;
    std::vector<std::string> lines;
    std::ifstream cFile = std::ifstream(filename);

    if (!cFile.is_open())
        throw FileNotFoundException(filename);

    while (std::getline(cFile, line))
        lines.push_back(line);

    cFile.close();

    return lines;
}

int main(int ac, char **av)
{
    Scanner scanner;
    std::size_t lineIndex = 1;
    std::vector<std::string> lines;

    if (ac < 2)
        return -1;

    try {

        lines = get_input_content(av[1]);

        for (std::size_t index = 0; index < lines.size(); index++, lineIndex++)
            lexical_analyzer(lines[index], scanner);

        // generate_output_file(scanner, av[1]);



    } catch (LexicalErrorException &le) {
        le.setLineIndex(lineIndex);
        generate_error_report(le, lines[lineIndex - 1], av[1]);
    } catch (FileNotFoundException &fe) {
        std::cerr << "File not found: " << fe.what() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Something wrong happened" << std::endl;
    }

    return 0;
}