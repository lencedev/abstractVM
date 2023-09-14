/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
** File description:
** CommandParser
*/

#ifndef COMMANDPARSER_HPP
    #define COMMANDPARSER_HPP

#include <vector>
#include <unordered_map>
#include <include.hpp>
#include "IOperand.hpp"

// poly : methods from commandParser class take an IOperand and we can use any kind of operand

class CommandParser {
    private:
        vector<IOperand*> _stack;
        // operand stack
        unordered_map<string, IOperand*> _register;
        // stock operand by name
        using cmd_function = void (CommandParser::*)(const string&, const string&);
        typedef void (CommandParser::*CheckFunc)(double value);
        unordered_map<string, cmd_function> _commands;
        // stock pointer's function to method to execute commands (_command)
        unordered_map<string, CheckFunc> _checkFunctions;
        // check over/underflow errors
        void executePush(const string& type, const string& value);
        void executeAdd(const string& type, const string& value);
        void executeMul(const string& type, const string& value);
        void executeDiv(const string& type, const string& value);
        void executeDump(const string& type, const string& value);
        void executeSub(const string& type, const string& value);
        void executeMod(const string& type, const string& value);
        void executePop(const string& type, const string& value);
        void executeClear(const string& type, const string& value);
        void executeDup(const string& type, const string& value);
        void executeSwap(const string& type, const string& value);
        void executePrint(const string& type, const string& value);
        void executeExit(const string& type, const string& value);
        void executeLoad(const string &type, const string &value);
        void executeAssert(const string &type, const string &value);
        void executeComment(const string &type, const string &value);
        void executeStore(const string &type, const string &value);
        eOperandType stringToType(const string& str);

    public:
        CommandParser();
        void parseCommand(const string& command);
        void parseCommandWithoutValue(const string& command);
        void parseCommandWithValue(const string& command);
        void executeCommand(const string& cmd, const string& type, const string& value);
        void checkUnderflowOverflow(const string& value, const string& type);
        void checkInt8(double value);
        void checkInt16(double value);
        void checkInt32(double value);
        void checkFloat(double value);
        void checkDouble(double value);
};

#endif // COMMANDPARSER_HPP
