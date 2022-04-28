#include <iostream>
#include <fstream>

#include "headers/lexical_analyzer.hpp"
#include "headers/exceptions/LexicalErrorException.hpp"
#include "headers/exceptions/FileNotFoundException.hpp"

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

void generate_error_report(LexicalErrorException &e, const std::string &line, const std::string &filename)
{
    std::ofstream outputFile(filename + ".out");

    if (outputFile.is_open()) {
        outputFile << e.what() << "\n";
        outputFile << line << "\n";

        outputFile.close();
    }
}

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

        generate_output_file(scanner, av[1]);

    } catch (LexicalErrorException &e) {
        e.setLineIndex(lineIndex);
        generate_error_report(e, lines[lineIndex - 1], av[1]);
    } catch (FileNotFoundException &e) {
        std::cerr << "File not found: " << e.what() << "\n";
    } catch (std::exception &e) {
        std::cerr << "Something wrong happened\n";
    }

    return 0;
}