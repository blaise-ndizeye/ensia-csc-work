#pragma once
#include "coin.h"
#include <iostream>
using namespace std;

class Coin10 : public Coin {
public:
  Coin10() = default;
  virtual bool toss() const override;
  virtual double getValue() const override;
};