# Lab 9: Vector Implementation Exercise

## Documentation

[📄 View Lab 9 Instructions (PDF)](../lab_9.pdf)

## Overview

This lab focuses on implementing a Vector class hierarchy in C++. The main objectives are:

1. Create a basic Vector class for integer arrays
2. Implement a derived BitVector class for binary operations
3. Practice inheritance and polymorphism
4. Handle dynamic memory management

## Requirements

### Vector Class Requirements

- Dynamic array implementation
- Size management with proper memory allocation
- Basic vector operations:
  - Adding elements
  - Resizing
  - Vector addition
  - Vector multiplication
  - Printing vectors

### BitVector Class Requirements

- Must inherit from Vector class
- Only allows binary values (0 and 1)
- Overrides vector operations:
  - Addition becomes OR operation
  - Multiplication becomes AND operation
- Input validation for binary values

## Class Structure

### Vector Class

- Constructor with size parameter
- Destructor
- Methods for vector operations
  - setSize
  - setAll
  - add
  - print
  - sumVect
  - prodVect

### BitVector Class

- Inherits from Vector
- Special operations for binary vectors
- Bit validation
- Overridden operations:
  - setAll
  - add
  - sumVect (using OR operation)
  - prodVect (using AND operation)

## Building and Running

```bash
mkdir build
cd build
cmake ..
make
```

## Testing

To test your implementation:

1. Create Vector and BitVector objects
2. Try various operations and verify results
3. Ensure proper memory management
4. Test error handling for invalid inputs

## Note

Make sure to implement the Rule of Three:

- Copy constructor
- Assignment operator
- Destructor
