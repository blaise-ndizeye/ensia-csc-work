#pragma once
#include <exception>

using namespace std;

class StackOverflowException : public exception {
public:
  StackOverflowException();
  virtual ~StackOverflowException() = default;
  virtual const char *what() const noexcept override;
};

class StackEmptyException : public exception {
public:
  StackEmptyException();
  virtual ~StackEmptyException() = default;
  virtual const char *what() const noexcept override;
};