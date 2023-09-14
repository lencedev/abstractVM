/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
** File description:
** Factory
*/

#include "Factory.hpp"
#include "Operand.hpp"

IOperand* Factory::createOperand(eOperandType type, const string& value) {
    switch(type) {
        case Int8: return createInt8(value);
        case Int16: return createInt16(value);
        case Int32: return createInt32(value);
        case Float: return createFloat(value);
        case Double: return createDouble(value);
        default: return nullptr;
    }
}
// determine the kind of operand to create depending of type passed in arg
// Operand creation depending of the type

IOperand* Factory::createInt8(const string& value) {
    return new Operand(eOperandType::Int8, value);
}

IOperand* Factory::createInt16(const string& value) {
    return new Operand(eOperandType::Int16, value);
}

IOperand* Factory::createInt32(const string& value) {
    return new Operand(eOperandType::Int32, value);
}

IOperand* Factory::createFloat(const string& value) {
    return new Operand(eOperandType::Float, value);
}

IOperand* Factory::createDouble(const string& value) {
    return new Operand(eOperandType::Double, value);
}
// init the good operand