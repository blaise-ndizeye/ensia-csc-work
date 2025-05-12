#include "../lib/exceptions.h"
#include <exception>

StackOverflowException::StackOverflowException() {}

const char *StackOverflowException::what() const noexcept {
  return "Stack overflow: Cannot add element to full stack!";
}

StackEmptyException::StackEmptyException() {}

const char *StackEmptyException::what() const noexcept {
  return "Stack empty: Cannot access elements from empty stack!";
}