#pragma once
#include <iostream>
using namespace std;

class Coin {
  static double balance;

public:
  Coin() = default;
  /*
   * 1 or True: Heads
   * 0 or False: Tails
   */
  virtual bool toss() const = 0; // heads or tails
  virtual double getValue() const = 0;
  static double getBalance();
  static void incrementBalance(const double &value = 10);
  static void decrementBalance(const double &value = 10);
  static void setBalance(const double &value);
  static bool randomBinary();
};