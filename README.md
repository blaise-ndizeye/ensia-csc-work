# Lab 11: Template Classes

For more details about this exercise, please refer to [Lab11.pdf](lab_11.pdf) and it's extra explanation from [Lab11_exercise_3_notes.pdf](lab11_ex3_notes.pdf).

## Exercise 2: Template DoubleSubscriptedArray Class

A C++ class that implements a double-subscripted array with overloaded operators for array manipulation.

## Class Description

The `DoubleSubscriptedArray` class provides functionality for creating and managing a 2D array using operator overloading. The array is internally stored as a 1D array with proper pointer arithmetic for accessing elements.

### Constructor

```cpp
DoubleSubscriptedArray(int rows = 10, int cols = 10);
```

Creates an array with specified number of rows and columns. Default size is 10x10.

### Operators

- `operator()(int row, int col)` - Access element at specified row and column (lvalue)
- `operator()(int row, int col) const` - Access element at specified row and column (rvalue)
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
    // Create 3x5 array
    DoubleSubscriptedArray arr(3, 5);

    // Set element at row 1, col 3
    arr(1, 3) = 25;

    // Print element
    cout << "Element at (1,3): " << arr(1, 3) << endl;

    // Print entire array
    cout << arr;

    // Compare arrays
    DoubleSubscriptedArray arr2(3, 5);
    if (arr != arr2) {
        cout << "Arrays are different" << endl;
    }

    // Input array values
    cout << "Enter array elements:" << endl;
    cin >> arr2;

    return 0;
}
```

## Implementation Details

- Uses a single-dimensional array internally to store elements
- Calculates element position using: `position = row * columns + column`
- Performs bounds checking on array access
- Supports both const and non-const element access
