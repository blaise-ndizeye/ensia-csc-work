#pragma once
#include <exception>
using namespace std;

class ArrayOutOfRangeError : public exception {
public:
  ArrayOutOfRangeError();
  virtual const char *what() const noexcept override;
};