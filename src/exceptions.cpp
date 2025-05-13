#include "../lib/exceptions.h"

ArrayOutOfRangeError::ArrayOutOfRangeError() {}

const char *ArrayOutOfRangeError::what() const noexcept {
  return "Error: Indices out of range!";
}