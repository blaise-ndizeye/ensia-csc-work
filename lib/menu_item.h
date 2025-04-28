#pragma once
#include <iostream>
using namespace std;

class MenuItem {
  string name;
  double price;

public:
  MenuItem(string name, double price);
  string getName() const;
  void setName(const string &);
  double getPrice() const;
  void setPrice(const double &);
  virtual void input();
  virtual void display() const;
  virtual double calculatePrice() const = 0;
};