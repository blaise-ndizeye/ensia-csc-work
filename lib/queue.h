#pragma once

template <class T> class Queue {
  int Qsize; // maximum number of elements in the queue
  int last;  // location of the last element "back"
  T *queuePtr;
  void setSize(const int &);

public:
  Queue(int = 10); // default constructor (queue size 10)
  ~Queue();
  bool push(const T &);
  bool pop(T &);
  bool isFull() const;
  bool isEmpty() const;
  void print() const;
};