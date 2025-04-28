#pragma once
#include "menu_item.h"
#include <iostream>
using namespace std;

class Appetizer : public MenuItem {
  char size; // S, M, L
  string description;
  bool vegeterian;

public:
  Appetizer(string name, double price, string description, bool vegeterian);
  char getSize() const;
  void seSize(const char &);
  string getDescription() const;
  void setDescription(const string &);
  bool getVegeterian() const;
  void setVegeterian(const bool &);
  virtual void input() override;
  virtual void display() const override;
  virtual double calculatePrice() const override;
};