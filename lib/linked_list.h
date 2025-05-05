#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.impl.h"
#include <iostream>
using namespace std;

template <class T> class LinkedList {
  Node<T> *head;

public:
  LinkedList();
  LinkedList(const LinkedList<T> &);
  ~LinkedList();

  // Overloaded assignment operator to avoid shallow copying
  LinkedList<T> operator=(const LinkedList<T> &);

  // A new node containing the given data is inserted at the front
  void add(T data);

  // A new node containing the given data is inserted at the given position in
  // the list
  void insertAt(int pos, T data);

  // The first incidence of the given data is removed from the list .
  // Returns true if data is found (and removed ), false otherwise
  bool remove(T data);

  // Empties the list , freeing up dynamically allocated memory
  void removeAll();

  // Prints the contents of the list to the standard output stream
  void printList();
};

#endif