#include "vector.h"
#include <iostream>
using namespace std;

Vector::Vector(int size) {
  if (size <= 0)
    throw invalid_argument("Please enter a valid size number");
  this->size = size;
  lastIndex = 0;
  data = new int[size]{0};
}

void Vector::setSize(const int &size) {
  if (size == this->size)
    return;

  int *newData = new int[size];
  int copySize = min(size, this->size);

  // Copy existing elements
  for (int i = 0; i < copySize; i++) {
    newData[i] = data[i];
  }

  // Initialize new elements to 0
  for (int i = copySize; i < size; i++) {
    newData[i] = 0;
  }

  delete[] data;
  data = newData;
  this->size = size;
}

void Vector::setAll(const int size, const int *newData) {
  setSize(size);
  for (int i = 0; i < size; i++) {
    data[i] = newData[i];
  }
}

void Vector::add(const int &el) {
  // If array is full, resize with a growth factor
  if (lastIndex == size) {
    int newSize = size * 2; // Double the size
    if (newSize == 0)
      newSize = 1; // Handle initial size 0

    int oldSize = size;
    setSize(newSize);
    lastIndex = oldSize;
  }

  data[lastIndex] = el;
  lastIndex++;
}

void Vector::print() const {
  cout << "(";
  for (int i = 0; i < size; i++) {
    cout << data[i] << (i + 1 == size ? "" : ", ");
  }
  cout << ") \n";
}

void Vector::sumVect(const Vector &v) {
  if (v.getSize() != size)
    throw invalid_argument("Only vectors of the same size can be added!");

  for (int i = 0; i < size; i++) {
    data[i] = data[i] + v.data[i];
  }
}

void Vector::prodVect(const Vector &v) {
  if (v.getSize() != size)
    throw invalid_argument("Only vectors of the same size can be multiplied!");

  for (int i = 0; i < size; i++) {
    data[i] = data[i] * v.data[i];
  }
}

const int *Vector::getData() const { return data; }

int Vector::getSize() const { return size; }

BitVector::BitVector(int size) : Vector(size) {}

void BitVector::validateBitNumber(const int &el) const {
  if (el != 0 && el != 1)
    throw invalid_argument(
        "Only numbers with 1s and 0s are allowed in BitVector");
}

void BitVector::setAll(const int size, const int *newData) {
  for (int i = 0; i < size; i++)
    validateBitNumber(newData[i]);

  Vector::setAll(size, newData);
}

void BitVector::add(const int &el) {
  validateBitNumber(el);
  Vector::add(el);
}

void BitVector::sumVect(const Vector &v) {
  if (v.getSize() != getSize())
    throw invalid_argument("Only vectors of the same size can be added!");

  int *summedData = new int[v.getSize()];
  for (int i = 0; i < getSize(); i++) {
    summedData[i] = getData()[i] || v.getData()[i];
  }

  setAll(getSize(), summedData);
  delete[] summedData;
}

void BitVector::prodVect(const Vector &v) {
  if (v.getSize() != getSize())
    throw invalid_argument("Only vectors of the same size can be multiplied!");

  int *multipliedData = new int[v.getSize()];
  for (int i = 0; i < getSize(); i++) {
    multipliedData[i] = getData()[i] && v.getData()[i];
  }

  setAll(getSize(), multipliedData);
  delete[] multipliedData;
}
