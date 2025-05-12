#include "../lib/stack.h"
#include "../lib/exceptions.h"
#include <iostream>
using namespace std;

template class Stack<char>;

template <class T> Stack<T>::Stack(int size) {
  this->size = size > 0 ? size : 10;
  top = -1;
  ptr = new T[size]{};
}

template <class T> Stack<T>::~Stack() { delete[] ptr; }

template <class T> void Stack<T>::add(const T &element) {
  if (isFull())
    throw StackOverflowException();

  top += 1;
  ptr[top] = element;
}

template <class T> void Stack<T>::pop(T &placeholder) {
  if (isEmpty())
    throw StackEmptyException();

  placeholder = ptr[top--];
}

template <class T> const T &Stack<T>::peek() const {
  if (isEmpty())
    throw StackEmptyException();

  return ptr[top];
}

template <class T> bool Stack<T>::isEmpty() const throw() { return top == -1; }

template <class T> bool Stack<T>::isFull() const throw() {
  return top == size - 1;
}

template <class T> istream &operator>>(istream &in, Stack<T> &st) {
  for (int i = 0; i < st.size; i++) {
    T element;
    cout << "Stack(" << i << ") = ";
    in >> element;
    st.add(element);
  }

  cout << "\n";
  return in;
}

template <class T> ostream &operator<<(ostream &out, const Stack<T> &st) {
  if (st.isEmpty()) {
    out << "[]";
    return out;
  }

  out << "[";
  for (int i = 0; i <= st.top; i++) {
    out << st.ptr[i];

    if (i != st.top) {
      out << ", ";
    }
  }

  out << "] \n";
  return out;
}

template istream &operator>> <char>(istream &, Stack<char> &);

template ostream &operator<< <char>(ostream &, const Stack<char> &);