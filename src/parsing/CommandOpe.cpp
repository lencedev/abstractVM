/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
** File description:
** CommandOpe
*/

#include "CommandParser.hpp"
#include "Factory.hpp"
#include "Exception.hpp"

void CommandParser::executeAdd(const string &type, const string &value) {
    if (_stack.size() < 2)
        throw StackUnderflowError();
    IOperand *op1 = _stack.back();
    _stack.pop_back();
    IOperand *op2 = _stack.back();
    _stack.pop_back();
    IOperand *result = *op1 + *op2;
    _stack.push_back(result);
}

void CommandParser::executeMul(const string &type, const string &value) {
        if (_stack.size() < 2)
            throw StackUnderflowError();
    IOperand *op1 = _stack.back();
    _stack.pop_back();
    IOperand *op2 = _stack.back();
    _stack.pop_back();
    IOperand *result = *op1 * *op2;
    _stack.push_back(result);
}

void CommandParser::executeSub(const string &type, const string &value) {
        if (_stack.size() < 2)
            throw StackUnderflowError();
    IOperand *op1 = _stack.back();
    _stack.pop_back();
    IOperand *op2 = _stack.back();
    _stack.pop_back();
    IOperand *result = *op2 - *op1;
    _stack.push_back(result);
}

void CommandParser::executeDiv(const string &type, const string &value) {
    if (_stack.size() < 2)
            throw StackUnderflowError();
    IOperand *op1 = _stack.back();
    _stack.pop_back();
    IOperand *op2 = _stack.back();
    _stack.pop_back();

    if (op1->toString() == "0")
        throw DivisionByZeroError();
    IOperand *result = *op2 / *op1;
    _stack.push_back(result);
}

void CommandParser::executeMod(const string &type, const string &value) {
    if (_stack.size() < 2)
        throw StackUnderflowError();
    IOperand *op1 = _stack.back();
    _stack.pop_back();
    IOperand *op2 = _stack.back();
    _stack.pop_back();

    if (op2->toString() == "0")
        throw DivisionByZeroError();
    IOperand *result = *op1 % *op2;
    if (result->toString() == "0")
        throw ModuloByZeroError();
    _stack.push_back(result);
}
