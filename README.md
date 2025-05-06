# Lab 11: Template Classes

This lab covers template classes in C++. For full exercise details, see [lab_11.pdf](lab_11.pdf).

## Exercise 2: Template Queue Class

### Description

Implementation of a generic Queue data structure using templates. The Queue follows First-In-First-Out (FIFO) principles, similar to a line of people waiting to be served.

### Features

- Template parameter for flexible type storage
- Array-based implementation
- Fixed-size queue with configurable capacity
- Operations:
  - `push()`: Adds element to the back of queue
  - `pop()`: Removes element from front of queue
  - `print()`: Displays queue contents
- Size management and overflow protection

### Usage Example

```cpp
// Integer queue
Queue<int> integers;
integers.push(4);
integers.push(8);
integers.push(9);

// String queue with custom size
Queue<string> words(5);
words.push("Blaise");
words.push("Lea");
words.push("Shema");

// Pop elements
int value;
if (integers.pop(value)) {
    cout << value << " removed from queue";
}

// Print queue contents
words.print(); // Shows current queue state
```

### Implementation Details

- Uses a dynamic array to store elements
- Maintains front and rear indices for queue operations
- Provides overflow and underflow checking
- Default capacity of 10 if not specified
