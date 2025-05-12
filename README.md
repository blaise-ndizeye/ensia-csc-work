# Stack Implementation with Exception Handling

For more details about this exercise, please refer to [Tutor_12.pdf](tutor_12.pdf).

## Exercise Description

Implementing a Stack data structure with proper exception handling using templates. The implementation demonstrates the use of custom exceptions for stack overflow and underflow conditions.

### Class Overview

```cpp
template <class T> class Stack {
  int size;
  int top;
  T *ptr;

public:
  Stack(int size = 10);
  ~Stack();
  void add(const T &) noexcept(false);   // May throw StackOverflowException
  const T &peek() const noexcept(false); // May throw StackEmptyException
  void pop(T &) noexcept(false);         // May throw StackEmptyException
  bool isEmpty() const noexcept;
  bool isFull() const noexcept;
  // ... additional operators
};
```

### Custom Exceptions

```cpp
class StackOverflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack overflow: Cannot add element to full stack";
    }
};

class StackEmptyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack empty: Cannot access elements from empty stack";
    }
};
```

### Key Features

1. **Template Implementation**

   - Can be used with any data type
   - Easily convertible to non-template class
   - Current implementation specializes for char type

2. **Exception Safety**

   - Custom exceptions for error handling
   - Strong exception guarantees
   - noexcept specifications where appropriate

3. **Stack Operations**
   - `add()`: Pushes element (may throw StackOverflowException)
   - `pop()`: Removes top element (may throw StackEmptyException)
   - `peek()`: Views top element (may throw StackEmptyException)
   - `isEmpty()` and `isFull()`: Status checks (noexcept)

### Usage Example

```cpp
try {
    Stack<char> stack(5);
    stack.add('A');
    char value;
    stack.pop(value);
} catch (const StackOverflowException& e) {
    std::cerr << "Stack overflow error: " << e.what() << '\n';
} catch (const StackEmptyException& e) {
    std::cerr << "Stack empty error: " << e.what() << '\n';
}
```

Note: While this implementation uses templates, it can be easily modified to work with specific types by removing the template syntax and specifying the desired type directly.
