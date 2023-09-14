/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>

class OverflowUnderflowError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Underflow or Overflow occurred.";
    }
};

class ModuloWithFloatError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Modulo operation not supported for floating point types.";
    }
};

class WrongTypeError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Wrong type.";
    }
};

class StackUnderflowError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Not enough values on the stack for the operation.";
    }
};

class DivisionByZeroError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Division by zero.";
    }
};

class ModuloByZeroError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Division by zero in modulo operation.";
    }
};

class ModuloFloatError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Modulo operation not supported for floating point types.";
    }
};

class FileAvmError : public std::exception {
public:
    const char * what () const throw () {
        return "Error : File must be .avm.";
    }
};

class OpenFileError : public std::exception {
public:
    const char * what () const throw () {
        return "Error : Can't open file.";
    }
};

class UsageError : public std::exception {
public:
    const char * what () const throw () {
        return "Error : Wrong arguments";
    }
};

class InvalidRegisterError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Invalid register operation.";
    }
};

class InvalidAssertionError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Assertion failed.";
    }
};

class EmptyStackError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Operation on empty stack.";
    }
};

class InvalidPrintError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Invalid print operation.";
    }
};

class InvalidCommandError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Invalid command format.";
    }
};

class StackEmptyError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Cannot perform operation on an empty stack.";
    }
};

class AssertionError : public std::exception {
public:
    const char * what () const throw () {
        return "Error: Assertion failed.";
    }
};

#endif /* !EXEPTION_HPP_ */
