#pragma once
#include <iostream>
using namespace std;

template <class T, class R> class Pair {
public:
  Pair(const T &t, const R &u) : first(t), second(u) {}
  T &get_first() { return first; }
  R &get_second() { return second; }
  const T &get_first() const { return first; }
  const R &get_second() const { return second; }

private:
  T first;
  R second;
};

template <class T, class R> void print_pair(const Pair<T, R> &p) {
  std::cout << '(' << p.get_first() << ", " << p.get_second() << ")\n";
}