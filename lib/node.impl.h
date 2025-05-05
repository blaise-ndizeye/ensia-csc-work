#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <class T> class Node {
public:
  T data;
  Node *next;
  Node(T d) { data = d; }
  Node(const Node *node) { data = node->data; }
};

#endif
