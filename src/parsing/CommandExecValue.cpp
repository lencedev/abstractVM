/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
** File description:
** CommandExecValue
*/

#include "CommandParser.hpp"
#include "Factory.hpp"
#include "Exception.hpp"


void CommandParser::executePush(const string& type, const string& value) {
    _stack.push_back(Factory::createOperand(stringToType(type), value));
}

void CommandParser::executeLoad(const string &type, const string &value) {
    if (_register.count(value) == 0)
        throw InvalidRegisterError();
    _stack.push_back(_register[value]);
}

void CommandParser::executeStore(const string &type, const string &value) {
    if (_stack.empty())
        throw StackEmptyError();
    _register[value] = _stack.back();
    _stack.pop_back();
}

void CommandParser::executeAssert(const string &type, const string &value) {
    if (_stack.empty())
        throw StackEmptyError();
    IOperand *op = _stack.back();
    if(op->getType() != stringToType(type) || op->toString() != value) {
        throw AssertionError();
    }
}
