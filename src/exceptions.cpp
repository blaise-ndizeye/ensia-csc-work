#include "../lib/exceptions.h"
#include <iostream>

MathException::MathException(const string &msg) : message(msg) {}

const char *MathException::what() const noexcept { return message.c_str(); }

DivideByZeroException::DivideByZeroException()
    : MathException("Error: Division by zero is not allowed!") {}

OverFlowException::OverFlowException()
    : MathException("Error: Number too large to process!") {}

RootOfNegativeException::RootOfNegativeException()
    : MathException("Error: Cannot calculate square root of negative number!") {
}