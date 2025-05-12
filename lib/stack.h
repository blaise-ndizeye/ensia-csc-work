#pragma once
#include "./exceptions.h"
#include <iostream>
using namespace std;

template <class T> class Stack {
  int size;
  int top;
  char *ptr;

public:
  Stack(int size = 10);
  ~Stack();
  void add(const T &) noexcept(false);   // Can throw StackOverflow exception
  const T &peek() const noexcept(false); // Can throw StackEmptyException
  void pop(T &) noexcept(false);         // Can throw StackEmpty exception
  bool isEmpty() const noexcept;
  bool isFull() const noexcept;

  template <class R> friend istream &operator>>(istream &, Stack<R> &);
  template <class R> friend ostream &operator<<(ostream &, const Stack<R> &);
};