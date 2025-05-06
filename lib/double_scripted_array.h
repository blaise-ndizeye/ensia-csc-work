#pragma once
#include <iostream>
using namespace std;

template <class T> class DoubleScriptedArray {
  int rowSize, columnSize;
  T *ptr;

public:
  DoubleScriptedArray(const int &rowSize = 10, const int &columnSize = 10);
  DoubleScriptedArray(const DoubleScriptedArray<T> &);
  ~DoubleScriptedArray();

  const DoubleScriptedArray &operator=(const DoubleScriptedArray<T> &);
  bool operator==(const DoubleScriptedArray<T> &) const;
  bool operator!=(const DoubleScriptedArray<T> &) const;
  const T &operator()(int rowP, int columnP) const;
  T &operator()(int rowP, int columnP);

  template <class R>
  friend ostream &operator<<(ostream &, const DoubleScriptedArray<R> &);

  template <class R>
  friend istream &operator>>(istream &, DoubleScriptedArray<R> &);

  int getRowSize() const;
  int getColumnSize() const;
};
