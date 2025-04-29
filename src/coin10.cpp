#include "../lib/coin10.h"
#include <iostream>
using namespace std;

bool Coin10::toss() const {
  bool tossValue = randomBinary();
  cout << "- Coin10 landed " << (tossValue ? "Head" : "Tail") << "\n";
  return tossValue;
}

double Coin10::getValue() const { return 10; }
