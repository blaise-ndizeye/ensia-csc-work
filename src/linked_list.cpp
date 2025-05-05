#include "../lib/linked_list.h"

template class LinkedList<int>;
template class LinkedList<string>;

template <class T> LinkedList<T>::LinkedList() { head = nullptr; }

template <class T> LinkedList<T>::LinkedList(const LinkedList<T> &other) {
  head = nullptr;
  Node<T> *current = other.head;

  while (current != nullptr) {
    add(current->data);
    current = current->next;
  }
}

template <class T> LinkedList<T>::~LinkedList() { removeAll(); }

template <class T>
LinkedList<T> LinkedList<T>::operator=(const LinkedList<T> &other) {
  if (this != &other) {
    removeAll();
    head = nullptr;
    Node<T> *current = other.head;

    while (current != nullptr) {
      add(current->data);
      current = current->next;
    }
  }
  return *this;
}

template <class T> void LinkedList<T>::add(T data) {
  Node<T> *newNode = new Node<T>(data);

  if (head == nullptr) {
    head = newNode;
    return;
  }

  newNode->next = head;
  head = newNode;
}

template <class T> void LinkedList<T>::insertAt(int pos, T data) {
  Node<T> *newNode = new Node<T>(data);

  if (pos == 0) {
    newNode->next = head;
    head = newNode;
    return;
  }

  // Traverse the list to find the node before the desired position
  Node<T> *current = head;
  int currentIndex = 0;

  while (current != nullptr && currentIndex < pos - 1) {
    current = current->next;
    currentIndex++;
  }

  if (current == nullptr) {
    delete newNode;
    throw out_of_range("Position out of bounds");
  }

  newNode->next = current->next;
  current->next = newNode;
}

template <class T> bool LinkedList<T>::remove(T data) {
  Node<T> *current = head;
  Node<T> *prev = nullptr;

  while (current != nullptr && current->data != data) {
    prev = current;
    current = current->next;
  }

  if (current == nullptr)
    return false;

  if (prev == nullptr) { // Removing head node
    head = current->next;
    delete current;
    return true;
  }

  prev->next = current->next;
  delete current;
  return true;
}

template <class T> void LinkedList<T>::removeAll() {
  while (head != nullptr) {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
  }
}

template <class T> void LinkedList<T>::printList() {
  Node<T> *current = head;

  while (current != nullptr) {
    cout << current->data;
    current = current->next;

    if (current != nullptr)
      cout << ", ";
  }

  cout << "\n";
}
