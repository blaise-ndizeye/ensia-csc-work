#include "../lib/coin20.h"
#include <iostream>
using namespace std;

bool Coin20::toss() const {
  bool tossValue = randomBinary();
  cout << "- Coin20 landed " << (tossValue ? "Head" : "Tail") << "\n";
  return tossValue;
}

double Coin20::getValue() const { return 20; }
