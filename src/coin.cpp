#include "../lib/coin.h"
#include <iostream>
using namespace std;

void Coin::setBalance(const double &value) {
  if (value < 0)
    throw invalid_argument("Balance must be positive");

  balance = value;
}

double Coin::getBalance() { return balance; }

void Coin::incrementBalance(const double &value) { balance += value; }

void Coin::decrementBalance(const double &value) {
  int newBalance = balance - value;

  if (newBalance < 0)
    throw invalid_argument("Value is greater than the current balace");

  balance = newBalance;
}

bool Coin::randomBinary() { return rand() % 2; }

double Coin::balance = 0.0;