    /*
    ** EPITECH PROJECT, 2023
    ** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
    ** File description:
    ** Operand
    */

    #ifndef OPERAND_HPP_
        #define OPERAND_HPP_

#include "IOperand.hpp"
#include <string>
#include <sstream>
#include <iomanip>


class Operand : public IOperand {
    // impl of IOp
    public:
        Operand(eOperandType type, const string& value);
        virtual string toString() const override;
        virtual eOperandType getType() const override; // get operand type (int8...)
        virtual IOperand* operator+(const IOperand& rhs) const override;
        virtual IOperand* operator-(const IOperand& rhs) const override;
        virtual IOperand* operator*(const IOperand& rhs) const override;
        virtual IOperand* operator/(const IOperand& rhs) const override;
        virtual IOperand* operator%(const IOperand& rhs) const override;
    private:
        // each Operand has eOperandType and double value
        eOperandType _type;
        double _value;
        string doubleToString(double value, eOperandType type) const;
};

    #endif /* !OPERAND_HPP_ */
