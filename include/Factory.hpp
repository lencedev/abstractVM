/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_

#include "IOperand.hpp"
// create operand of different types
class Factory {
    public:
        static IOperand* createOperand(eOperandType type, const string& value);
        // same createOperand, taking eOperandType and value,
        // returns pointer to new operand of this type with this value
    private:
        static IOperand* createInt8(const string& value);
        static IOperand* createInt16(const string& value);
        static IOperand* createInt32(const string& value);
        static IOperand* createFloat(const string& value);
        static IOperand* createDouble(const string& value);
        //  priv method used to create spe operand at each kind of type
};

#endif // FACTORY_HPP_
