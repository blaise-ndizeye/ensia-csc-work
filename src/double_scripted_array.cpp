#include "../lib/double_scripted_array.h"
#include <iostream>
using namespace std;

template class DoubleScriptedArray<string>;
template class DoubleScriptedArray<int>;

template <class T>
DoubleScriptedArray<T>::DoubleScriptedArray(const int &rowSize,
                                            const int &columnSize) {
  this->rowSize = rowSize > 0 ? rowSize : 10;
  this->columnSize = columnSize > 0 ? columnSize : 10;

  ptr = new T[this->rowSize * this->columnSize]{};
}

template <class T>
DoubleScriptedArray<T>::DoubleScriptedArray(
    const DoubleScriptedArray<T> &other) {
  rowSize = other.rowSize;
  columnSize = other.columnSize;
  ptr = new T[rowSize * columnSize];

  for (int i = 0; i < rowSize; i++) {
    for (int j = 0; j < columnSize; j++) {
      ptr[i * columnSize + j] = other(i, j);
    }
  }
}

template <class T> DoubleScriptedArray<T>::~DoubleScriptedArray() {
  delete[] ptr;
}

template <class T>
const DoubleScriptedArray<T> &
DoubleScriptedArray<T>::operator=(const DoubleScriptedArray<T> &other) {
  if (this != &other) {
    delete[] ptr;
    rowSize = other.rowSize;
    columnSize = other.columnSize;
    ptr = new T[rowSize * columnSize];

    for (int i = 0; i < other.getRowSize(); i++) {
      for (int j = 0; j < other.getColumnSize(); j++) {
        ptr[i * columnSize + j] = other(i, j);
      }
    }
  }

  return *this;
}

template <class T>
bool DoubleScriptedArray<T>::operator==(
    const DoubleScriptedArray<T> &other) const {
  int rowSize = getRowSize();
  int columnSize = getColumnSize();

  if (rowSize != other.getRowSize() || columnSize != other.getColumnSize())
    return false;

  for (int i = 0; i < rowSize; i++) {
    for (int j = 0; j < columnSize; j++) {
      if (ptr[i * columnSize + j] != other(i, j))
        return false;
    }
  }

  return true;
}

template <class T>
bool DoubleScriptedArray<T>::operator!=(
    const DoubleScriptedArray &other) const {
  return !(*this == other);
}

template <class T>
const T &DoubleScriptedArray<T>::operator()(int rowP, int columnP) const {
  if (rowP >= getRowSize() || columnP >= getColumnSize())
    throw out_of_range("Positions out of bounds!");

  return ptr[rowP * columnSize + columnP];
}

template <class T>
T &DoubleScriptedArray<T>::operator()(int rowP, int columnP) {
  if (rowP >= getRowSize() || columnP >= getColumnSize())
    throw out_of_range("Positions out of bounds!");

  return ptr[rowP * columnSize + columnP];
}

template <class T> int DoubleScriptedArray<T>::getRowSize() const {
  return rowSize;
}

template <class T> int DoubleScriptedArray<T>::getColumnSize() const {
  return columnSize;
}

template <class T>
ostream &operator<<(ostream &output, const DoubleScriptedArray<T> &array) {
  int rowSize = array.getRowSize();
  int columnSize = array.getColumnSize();

  for (int i = 0; i < rowSize; i++) {
    for (int j = 0; j < columnSize; j++) {
      output << array(i, j) << " ";
    }

    output << "\n";
  }

  output << "\n";
  return output;
}

template <class T>
istream &operator>>(istream &input, DoubleScriptedArray<T> &array) {
  int rowSize = array.getRowSize();
  int columnSize = array.getColumnSize();

  cout << "Enter " << rowSize << "×" << columnSize << " elements: \n";

  for (int i = 0; i < rowSize; i++) {
    for (int j = 0; j < columnSize; j++) {
      T element;

      cout << "(" << i << ", " << j << ") = ";
      input >> element;
      array(i, j) = element;
    }

    cout << "\n";
  }

  return input;
}

template std::ostream &operator<< <string>(std::ostream &,
                                           const DoubleScriptedArray<string> &);
template istream &operator>> <string>(istream &, DoubleScriptedArray<string> &);

template ostream &operator<< <int>(std::ostream &,
                                   const DoubleScriptedArray<int> &);
template istream &operator>> <int>(istream &, DoubleScriptedArray<int> &);