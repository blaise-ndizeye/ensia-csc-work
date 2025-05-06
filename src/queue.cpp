#include "../lib/queue.h"
#include <iostream>
using namespace std;

template class Queue<int>;
template class Queue<string>;

template <class T> Queue<T>::Queue(int Qsize) {
  setSize(Qsize);
  queuePtr = new T[Qsize];
  last = -1;
}

template <class T> Queue<T>::~Queue() { delete[] queuePtr; }

template <class T> void Queue<T>::setSize(const int &size) {
  Qsize = size > 0 ? size : 10;
}

template <class T> bool Queue<T>::push(const T &element) {
  if (isFull())
    return false;

  int newLastIndex = last + 1;
  queuePtr[newLastIndex] = element;
  last = newLastIndex;
  return true;
}

template <class T> bool Queue<T>::pop(T &placeholder) {
  if (isEmpty())
    return false;

  placeholder = queuePtr[0]; // Store an element to be removed

  for (int i = 0; i < last; i++) {
    queuePtr[i] = queuePtr[i + 1];
  }

  last -= 1;
  return true;
}

template <class T> bool Queue<T>::isEmpty() const { return last == -1; }

template <class T> bool Queue<T>::isFull() const { return last + 1 >= Qsize; }

template <class T> void Queue<T>::print() const {
  if (isEmpty())
    return;

  for (int i = 0; i <= last; i++) {
    cout << queuePtr[i];

    if (i != last) {
      cout << ", ";
    }
  }
}