#include "../lib/coin50.h"
#include <iostream>
using namespace std;

bool Coin50::toss() const {
  bool tossValue = randomBinary();
  cout << "- Coin50 landed " << (tossValue ? "Head" : "Tail") << "\n";
  return tossValue;
}

double Coin50::getValue() const { return 50; }
