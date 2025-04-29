#pragma once
#include "coin.h"
#include <iostream>
using namespace std;

class Coin20 : public Coin {
public:
  Coin20() = default;
  virtual bool toss() const override;
  virtual double getValue() const override;
};