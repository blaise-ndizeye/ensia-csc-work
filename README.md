# Input Validation Program Documentation

For more details about this exercise, please refer to [Lab_12.pdf](lab_12.pdf) Exercise 2.

## Overview

This program demonstrates robust input validation for numeric values using C++ exception handling mechanisms.

## Implementation Details

### Key Components

#### Exception Handling Setup

```cpp
cin.exceptions(iostream::failbit);  // Enable exception throwing for input operations
```

#### Main Input Loop

```cpp
do {
    cout << "Enter a number between 1 and 10" << endl;
    cin >> num;

    if (cin.peek() != '\n') {
        throw &num;
    }

    if (num < 1 || num > 10) {
        cout << "Illegal value " << num << " entered. Try again." << endl;
    }
} while (num < 1 || num > 10);
```

#### Exception Handling Cases

```cpp
try {
    // Input logic here
} catch (iostream::failure &iof) {
    // Handle non-numeric input
    cout << "Non-integer value. Please enter a number." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
} catch (int *pnum) {
    // Handle trailing characters
    cout << "Non-integer value. You entered something after " << *pnum;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    *pnum = 0;
}
```

### Features

#### Input Validation

- **Checks for non-numeric input**
- **Validates range (1-10)**
- **Detects trailing characters**

#### Error Recovery

- Clears error flags
- Flushes input buffer
- Resets variables

#### User Feedback

- Clear error messages
- Prompts for correct input
- Success confirmation

### Error Handling

| Error Type          | Handling Mechanism            | User Message                                              |
| ------------------- | ----------------------------- | --------------------------------------------------------- |
| Non-numeric input   | `iostream::failure` exception | "Non-integer value. Please enter a number."               |
| Trailing characters | Pointer exception             | "Non-integer value. You entered something after [number]" |
| Out of range        | Conditional check             | "Illegal value [number] entered. Try again."              |

## Usage Example

```
Enter a number between 1 and 10
abc
Non-integer value. Please enter a number.
15
Illegal value 15 entered. Try again.
5
Value 5 correctly entered! Thank you.
```

## Dependencies

```cpp
#include <iostream>
#include <limits>
```
