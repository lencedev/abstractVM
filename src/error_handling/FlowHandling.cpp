/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
** File description:
** FlowHandling
*/

#include <include.hpp>
#include <Factory.hpp>
#include <CommandParser.hpp>
#include <Exception.hpp>
/*
void CommandParser::checkUnderflowOverflow(const string &value, const string &type) {
    char* endPtr;
    double val = strtod(value.c_str(), &endPtr);

    if (endPtr == value.c_str())
        return;
    auto it = _checkFunctions.find(type);
    if(it != _checkFunctions.end())
        (this->*(it->second))(val);
    else
        return;
}
*/

void CommandParser::checkUnderflowOverflow(const string &value, const string &type) {
    char* endPtr;
    double val = strtod(value.c_str(), &endPtr);

    if (endPtr == value.c_str())
        return;
    auto it = _checkFunctions.find(type);
    if(it != _checkFunctions.end()) {
            (this->*(it->second))(val);
    } else
        return;
}

void CommandParser::checkInt8(double value) {
    if (value < numeric_limits<int8_t>::lowest() ||
            value > numeric_limits<int8_t>::max()) {
        throw OverflowUnderflowError();
    }
}

void CommandParser::checkInt16(double value) {
    if (value < numeric_limits<int16_t>::lowest() ||
            value > numeric_limits<int16_t>::max()) {
            throw OverflowUnderflowError();
    }
}

void CommandParser::checkInt32(double value) {
    if (value < numeric_limits<int32_t>::lowest() ||
            value > numeric_limits<int32_t>::max()) {
        throw OverflowUnderflowError();
    }
}

void CommandParser::checkFloat(double value) {
    if (value < numeric_limits<float>::lowest() ||
            value > numeric_limits<float>::max()) {
        throw OverflowUnderflowError();
    }
}

void CommandParser::checkDouble(double value) {
    if (value < numeric_limits<double>::lowest() ||
            value > numeric_limits<double>::max()) {
        throw OverflowUnderflowError();
    }
}
