/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
** File description:
** IOperand
*/

#include <include.hpp>

#ifndef IOPERAND_HPP_
    #define IOPERAND_HPP_

// interface

enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

// define operations can be done on numbers
// git status

class IOperand
{
    public :
        virtual std :: string toString () const = 0;
        virtual eOperandType getType () const = 0; // returns the type of instance
        virtual IOperand * operator +( const IOperand & rhs ) const = 0; // sum
        virtual IOperand * operator -( const IOperand & rhs ) const = 0; // difference
        virtual IOperand * operator *( const IOperand & rhs ) const = 0; // product
        virtual IOperand * operator /( const IOperand & rhs ) const = 0; // quotient
        virtual IOperand * operator %( const IOperand & rhs ) const = 0; // modulo
        virtual ~ IOperand () {}
};

#endif /* !IOPERAND_HPP_ */
