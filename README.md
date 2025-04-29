# Coin System

A C++ implementation of a coin system with different coin denominations (10, 20, 50) and coin tossing functionality.

## Documentation

[View Lab 10 Assessment Instructions](lab_10.pdf)

## Project Structure

The project consists of the following files:

### Header Files (`lib/`)

- `coin.h` - Base abstract class for coins
- `coin10.h` - 10-value coin implementation
- `coin20.h` - 20-value coin implementation
- `coin50.h` - 50-value coin implementation

### Source Files (`src/`)

- `coin.cpp` - Core coin functionality implementation
- `coin10.cpp` - 10-value coin behavior
- `coin20.cpp` - 20-value coin behavior
- `coin50.cpp` - 50-value coin behavior
- `main.cpp` - Main program entry point

## Features

- Abstract coin base class with:

  - Virtual coin tossing functionality (heads/tails)
  - Virtual coin value getter
  - Static balance tracking and management
  - Random binary generator for tossing

- Concrete coin implementations for different denominations:
  - 10-value coin
  - 20-value coin
  - 50-value coin

## Build Instructions

The project uses CMake as its build system. To build:

```bash
mkdir build
cd build
cmake ..
make
```
