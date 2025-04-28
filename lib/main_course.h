#pragma once
#include "menu_item.h"
#include <iostream>
using namespace std;

class MainCourse : public MenuItem {
  int protein;
  string sideDish;
  string cookingStyle;

public:
  MainCourse(string name, double price, int protein, string sideDish,
             string cookingStyle);
  int getProtein() const;
  void setProtein(const int &);
  string getSideDish() const;
  void setSideDish(const string &);
  string getCookingStyle() const;
  void setCookingStyle(const string &);
  virtual void input() override;
  virtual void display() const override;
  virtual double calculatePrice() const override;
};