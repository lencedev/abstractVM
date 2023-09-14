/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
** File description:
** CommandParser
*/

#include <include.hpp>
#include <Factory.hpp>
#include <CommandParser.hpp>
#include "Exception.hpp"

CommandParser::CommandParser() : _commands({
        {"push", &CommandParser::executePush},
        {"dump", &CommandParser::executeDump},
        {"dup", &CommandParser::executeDup},
        {"swap", &CommandParser::executeSwap},
        {"print", &CommandParser::executePrint},
        {"exit", &CommandParser::executeExit},
        {"clear", &CommandParser::executeClear},
        {"pop", &CommandParser::executePop},
        {"add", &CommandParser::executeAdd},
        {"sub", &CommandParser::executeSub},
        {"mul", &CommandParser::executeMul},
        {"div", &CommandParser::executeDiv},
        {"mod", &CommandParser::executeMod},
        {"load", &CommandParser::executeLoad},
        {"assert", &CommandParser::executeAssert},
        {"comment", &CommandParser::executeComment},
        {"store", &CommandParser::executeStore},
                                            }),
        _checkFunctions({
        {"int8", &CommandParser::checkInt8},
        {"int16", &CommandParser::checkInt16},
        {"int32", &CommandParser::checkInt32},
        {"float", &CommandParser::checkFloat},
        {"double", &CommandParser::checkDouble},
      }) {}

void CommandParser::executeCommand(const string &cmd, const string &type, const string &value) {
    auto it = _commands.find(cmd);
    if(it != _commands.end())
        (this->*(it->second))(type, value);
    else
        return;
    return;
}

string trim(const string &s) {
    auto start = s.begin();

    while (start != s.end() && isspace(*start))
        start++;
    auto end = s.end();

    do
        end--;
    while (distance(start, end) > 0 && isspace(*end));
    return string(start, end + 1);
}

void CommandParser::parseCommandWithValue(const string &command) {
    regex command_with_value_regex(R"(^(\w+)\s+(\w+)\((\S+)\)$)");
    smatch match;

    if (regex_search(command, match, command_with_value_regex) && match.size() > 1) {
        string cmd = match.str(1);
        string type = match.str(2);
        string value = match.str(3);

        checkUnderflowOverflow(value, type);
        executeCommand(cmd, type, value);
    } else {
        throw InvalidCommandError();
    }
}

void CommandParser::parseCommandWithoutValue(const string &command) {
    regex command_without_value_regex(R"(^(\w+)$)");
    smatch match;

    if (regex_search(command, match, command_without_value_regex) && match.size() > 1) {
        string cmd = match.str(1);
        executeCommand(cmd, "", "");
    } else {
        throw InvalidCommandError();
    }
}

void CommandParser::parseCommand(const string &command) {
    string trimmedCommand = trim(command);

    if (trimmedCommand.empty())
        return;

    size_t semicolonPos = trimmedCommand.find(';');
    if (semicolonPos != string::npos)
        trimmedCommand = trimmedCommand.substr(0, semicolonPos);

    trimmedCommand = trim(trimmedCommand);

    if (trimmedCommand.empty())
        return;

    regex check_value(R"(\w+\(\S+\)$)");

    if (regex_search(trimmedCommand, check_value))
        parseCommandWithValue(trimmedCommand);
    else
        parseCommandWithoutValue(trimmedCommand);
}


eOperandType CommandParser::stringToType(const string &str) {
    static const map<string, eOperandType> strToTypeMap {
        {"int32", Int32},
        {"int16", Int16},
        {"int8", Int8},
        {"float", Float},
        {"double", Double}
    };
    auto it = strToTypeMap.find(str);
    if (it != strToTypeMap.end())
        return it->second;
    return Int32;
}
