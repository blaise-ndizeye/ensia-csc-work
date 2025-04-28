#pragma once
#include "menu_item.h"
#include <iostream>
using namespace std;

class Appetizer : public MenuItem {
  string description;
  bool vegeterian;

public:
  Appetizer(string name, double price, string description, bool vegeterian);
  string getDescription() const;
  void setDescription(const string &);
  bool getVegeterian() const;
  void setVegeterian(const bool &);
  virtual void input() override;
  virtual void display() override;
  virtual double calculatePrice() const override;
};