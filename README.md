# Exception Handling in C++

## Exercise Description

The exercise demonstrates handling exceptions in C++ using a simple array access example.

### Code Example

```cpp
int s[5]{1, 2, 3};
// string s = "Hello" ->

try {
  cout << "At index 12: " << s[12] << "\n";
  // cout << "At index 12: " << s.at(12) << "\n"; This will throw an error
  cout << "No exception thrown." << "\n";
} catch (exception &e) {
  cout << "\nException caught: " << e.what() << endl;
}
```

### Key Points

1. **Array Initialization**

   - Creates an array `s` with 5 elements
   - Initializes first three elements (1, 2, 3)
   - Remaining elements default to 0

2. **Try Block Implementation**

   - Attempts to access an out-of-bounds index (12)
   - Includes error-prone operation
   - It doesn't throw an error but it'll display a garbage value at that position since the program is attempting to access the out of bound memory.

3. **Exception Handling**
   - Uses standard exception catching
   - Demonstrates proper error message display
   - Shows safe error handling practices

### Purpose

This exercise teaches students:

- Basic exception handling syntax in C++
- Safe handling of runtime errors
- Array bounds checking behavior
- Standard exception class usage

The example illustrates proper error handling techniques to prevent program crashes when accessing invalid array indices.
