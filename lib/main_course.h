#pragma once
#include "menu_item.h"
#include <iostream>
using namespace std;

class MainCourse : public MenuItem {
  int protein;
  string sideDish;
  string cookingStyle;
  double extraProteinWeight;
  double proteinPricePerKg;

public:
  MainCourse(string name, double price, int protein, string sideDish,
             string cookingStyle, double extraProteinWeight,
             double proteinPricePerKg);
  int getProtein() const;
  void setProtein(const int &);
  double getExtraProteinWeight() const;
  void setExtraProteinWeight(const double &);
  double getProteinPricePerKg() const;
  void setProteinPricePerKg(const double &);
  string getSideDish() const;
  void setSideDish(const string &);
  string getCookingStyle() const;
  void setCookingStyle(const string &);
  virtual void input() override;
  virtual void display() const override;
  virtual double calculatePrice() const override;
};