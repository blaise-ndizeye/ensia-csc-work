#pragma once
#include <iostream>
using namespace std;

template <class T, class R> class Pair {
public:
  Pair(const T &t, const R &u);
  T &get_first();
  R &get_second();
  const T &get_first() const;
  const R &get_second() const;

private:
  T first;
  R second;
};

template <class T, class R> void print_pair(const Pair<T, R> &p) {
  std::cout << '(' << p.get_first() << ", " << p.get_second() << ")\n";
}

template <class T, class R>
Pair<T, R>::Pair(const T &t, const R &u) : first(t), second(u) {}

template <class T, class R> T &Pair<T, R>::get_first() { return first; }

template <class T, class R> R &Pair<T, R>::get_second() { return second; }

template <class T, class R> const T &Pair<T, R>::get_first() const {
  return first;
}

template <class T, class R> const R &Pair<T, R>::get_second() const {
  return second;
}
