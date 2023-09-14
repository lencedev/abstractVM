/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
** File description:
** CommandExec
*/

#include "CommandParser.hpp"
#include "Factory.hpp"
#include "Exception.hpp"

void CommandParser::executeDump(const string& type, const string& value) {
    for (auto it = _stack.rbegin(); it != _stack.rend(); ++it)
            cout << (*it)->toString() << '\n';
}

void CommandParser::executePop(const string& type, const string& value) {
    if (_stack.empty())
        throw StackUnderflowError();
    delete _stack.back();
    _stack.pop_back();
}

void CommandParser::executeDup(const string &type, const string &value) {
    if (_stack.empty())
        throw StackUnderflowError();
    IOperand* op1 = _stack.back();
    _stack.push_back(Factory::createOperand(op1->getType(), op1->toString()));
}

void CommandParser::executeSwap(const string &type, const string &value) {
    if (_stack.size() < 2)
        throw StackUnderflowError();
    IOperand* op1 = _stack.back();
    _stack.pop_back();
    IOperand* op2 = _stack.back();
    _stack.pop_back();
    _stack.push_back(op1);
    _stack.push_back(op2);
}

void CommandParser::executePrint(const string& type, const string& value) {
    if (_stack.empty())
        throw StackEmptyError();
    IOperand* op = _stack.back();
    if(op->getType() != Int8)
        throw WrongTypeError();
    int ascii_value = stoi(op->toString());
    if(ascii_value > 127 || ascii_value < 0 )
        throw OverflowUnderflowError();
    cout << static_cast<char>(ascii_value) << endl;
}

void CommandParser::executeClear(const string &type, const string &value) {
    for (auto & operand : _stack)
        delete operand;
    _stack.clear();
}

void CommandParser::executeExit(const string &type, const string &value) {
    exit(0);
}

void CommandParser::executeComment(const string &type, const string &value) {
    // nothing
}
