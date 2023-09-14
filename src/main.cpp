/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
** File description:
** main
*/

#include <include.hpp>
#include <error_handling.hpp>
#include <CommandParser.hpp>

int main(int ac, char *av[])
{
    ifstream avmFile(av[1]);
    string line;
    CommandParser parser;

    try {
    if (ac > 1) {
            while (getline(avmFile, line)) {
                if (line.front() != ';')
                    parser.parseCommand(line);
                }
            }
    else {
    vector<string> lines;
    while (getline(cin, line)) {
        if (line == ";;") {
            for (const auto& command : lines)
                parser.parseCommand(command);
            lines.clear();
            exit(0);
        } else
            lines.push_back(line);
        }
    }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
