# Linked List Implementation Exercise

This project implements a templated singly linked list data structure in C++.

## Overview

The exercise involves creating a generic linked list class that supports basic operations like:

- Adding elements
- Inserting at specific positions
- Removing elements
- Handling copy operations properly

## Requirements

- C++ compiler with template support
- Basic understanding of pointers and dynamic memory management

## Implementation Details

### Core Classes

1. [`Node`](lib/node.h) Template Class:

```cpp
template <class T>
class Node {
    T data;
    Node* next;
    // ... constructors and methods
};
```

2. [`LinkedList`](lib/linked_list.h) Template Class:

```cpp
template <class T>
class LinkedList {
    Node<T>* head;
    // ... methods for list operations
};
```

### Key Operations

The implementation includes:

- Default constructor
- Copy constructor
- Assignment operator
- Destructor
- `add()` - Adds element at front
- `insertAt()` - Inserts at specific position
- `remove()` - Removes first occurrence
- `removeAll()` - Clears list
- `printList()` - Prints contents

### Memory Management

Special attention is needed for:

- Proper deep copying in copy constructor and assignment
- Clean deletion of nodes in destructor
- Handling edge cases (empty list, invalid positions)

## Example Usage

```cpp
LinkedList<int> list1;
list1.add(14);
list1.add(20);
list1.add(26);

list1.printList(); // Output: 26, 20, 14

list1.insertAt(2, 199);
list1.printList(); // Output: 26, 20, 199, 14
```

## File Structure

```
.
├── lib/
│   ├── node.h
│   └── linked_list.h
└── src/
    ├── linked_list.cpp
    └── main.cpp
```

## Full Requirements

For detailed requirements and specifications, see [Tutorial 11 PDF](tutor_11.pdf).

## Unit Testing

Ensure to test:

- Memory management
- Edge cases
- Copy operations
- Insert/remove operations

## Common Pitfalls

- Memory leaks in destructor/copy operations
- Incorrect handling of head pointer
- Missing edge cases in insert/remove
- Shallow vs deep copying issues

## License

This is an educational exercise.
