#pragma once
#include "coin.h"
#include <iostream>
using namespace std;

class Coin50 : public Coin {
public:
  Coin50() = default;
  virtual bool toss() const override;
  virtual double getValue() const override;
};