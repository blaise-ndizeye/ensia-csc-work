#pragma once
#include "menu_item.h"
#include <iostream>
using namespace std;

class Dessert : public MenuItem {
  string flavor;
  bool glutenFree;

public:
  Dessert(string name, double price, string flavor, bool glutenFree);
  string getFlavor() const;
  void setFlavor(const string &);
  bool getGlutenFree() const;
  void setGlutenFree(const bool &);
  virtual void input() override;
  virtual void display() override;
  virtual double calculatePrice() const override;
};