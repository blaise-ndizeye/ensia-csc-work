#pragma once
#include <exception>
#include <iostream>
using namespace std;

class MathException : public exception {
protected:
  string message;

public:
  MathException(const string &);
  virtual const char *what() const noexcept override;
};

class DivideByZeroException : public MathException {
public:
  DivideByZeroException();
};

class OverFlowException : public MathException {
public:
  OverFlowException();
};

class RootOfNegativeException : public MathException {
public:
  RootOfNegativeException();
};