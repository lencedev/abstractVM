/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
** File description:
** Operand
*/

#include "Factory.hpp"
#include "Operand.hpp"
#include "Exception.hpp"


Operand::Operand(eOperandType type, const string& value) : _type(type), _value(stod(value)) {}

string Operand::toString() const {
    ostringstream strs;
    if (_type == Int8 || _type == Int16 || _type == Int32)
        strs << fixed << setprecision(0) << _value;
    else
        strs << fixed << setprecision(3) << _value;
    return strs.str();
}

eOperandType Operand::getType() const {
    return _type;
}

IOperand* Operand::operator+(const IOperand& rhs) const {
    double res = _value + stod(rhs.toString());
    return Factory::createOperand(_type, to_string(res));
}

IOperand* Operand::operator-(const IOperand& rhs) const {
    double res = _value - stod(rhs.toString());
    return Factory::createOperand(_type, to_string(res));
}

IOperand* Operand::operator*(const IOperand& rhs) const {
    double res = _value * stod(rhs.toString());
    return Factory::createOperand(_type, to_string(res));
}

IOperand* Operand::operator/(const IOperand& rhs) const {
    double divisor = stod(rhs.toString());
    if (divisor == 0.0)
        throw DivisionByZeroError();
    double res = _value / divisor;
    eOperandType result_type = std::max(_type, rhs.getType());
    return Factory::createOperand(result_type, to_string(res));
}

IOperand* Operand::operator%(const IOperand &rhs) const {
    if (_type == Float || _type == Double || rhs.getType() == Float || rhs.getType() == Double)
        throw ModuloFloatError();
    int res = static_cast<int>(_value) % static_cast<int>(stod(rhs.toString()));
    return Factory::createOperand(_type, to_string(res));
}
