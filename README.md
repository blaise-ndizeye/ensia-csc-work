# Lab 12: Exception Handling for Template Classes

For more details about this exercise, please refer to [Lab12.pdf](lab_12.pdf) and Exercise 3 [Lab11.pf](lab_11.pdf)

## Exercise 3: Exception Handling for DoubleSubscriptedArray Class

A C++ template class that implements a double-subscripted array with exception handling for invalid array access.

## Exception Class

```cpp
class ArrayOutOfRangeError : public exception {
public:
  ArrayOutOfRangeError();
  virtual const char *what() const noexcept override;
};
```

## Class Description

The `DoubleSubscriptedArray` class now includes exception handling for out-of-range array access.

### Constructor

```cpp
DoubleSubscriptedArray(int rows = 10, int cols = 10);
```

Creates an array with specified number of rows and columns. Default size is 10x10.

### Operators

- `operator()(int row, int col)` - Access element at specified row and column (lvalue)
  - Throws `ArrayOutOfRangeError` if indices are invalid
- `operator()(int row, int col) const` - Access element at specified row and column (rvalue)
  - Throws `ArrayOutOfRangeError` if indices are invalid
- `operator==` - Compare two arrays for equality
- `operator!=` - Compare two arrays for inequality
- `operator=` - Assignment operator for array copying
- `operator<<` - Output array in row/column format
- `operator>>` - Input values into array

## Example Usage

```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        // Create 3x5 array
        DoubleSubscriptedArray arr(3, 5);

        // Set element at row 1, col 3
        arr(1, 3) = 25;

        // Try to access invalid element
        arr(5, 3) = 10;  // Will throw ArrayOutOfRangeError
    }
    catch (const ArrayOutOfRangeError& e) {
        cerr << e.what() << '\n';
    }

    return 0;
}
```

## Implementation Details

- Uses a single-dimensional array internally to store elements
- Calculates element position using: `position = row * columns + column`
- Throws `ArrayOutOfRangeError` exception for invalid array access instead of terminating
- Supports both const and non-const element access
- Exception includes information about the invalid indices that caused the error
