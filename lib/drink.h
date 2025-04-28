#pragma once
#include "menu_item.h"
#include <iostream>
using namespace std;

class Drink : public MenuItem {
  string type;
  int servingSize;
  string temperature; // hot or cold

public:
  Drink(string name, double price, string type, int servingSize,
        string temperature);
  string getType() const;
  void setType(const string &);
  int getServingSize() const;
  void setServingSize(const int &);
  string getTemperature() const;
  void setTemperature(const string &);
  virtual void input() override;
  virtual void display() override;
  virtual double calculatePrice() const override;
};