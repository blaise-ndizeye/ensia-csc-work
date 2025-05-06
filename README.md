# Lab 11: Template Classes

This lab covers template classes in C++. For full exercise details, see [lab_11.pdf](lab_11.pdf).

## Exercise 1: Template Pair Class

### Description

Implementation of a template class `Pair` that can store two values of potentially different types. The class demonstrates basic template syntax and member functions.

### Features

- Template parameters `T` and `R` for flexible type storage
- Constructor taking const references to initialize members
- Getter methods for both elements (const and non-const versions)
- Friend function for printing pair contents

### Usage Example

```cpp
Pair<int, int> integers(1, 3);
Pair<double, double> reals(4.5, 3.3);
Pair<string, int> map("Hello world", 101);

// Access elements
cout << integers.get_first(); // prints 1
cout << reals.get_second();   // prints 3.3

// Print pairs
print_pair(map); // prints (Hello world, 101)

// Modify elements
map.get_first() = "C++";
```

## More Exercises

Additional exercise documentation will be added here
