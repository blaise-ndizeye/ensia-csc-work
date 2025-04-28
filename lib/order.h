#pragma once
#include "menu_item.h"
#include <iostream>
#include <vector>
using namespace std;

class Order {
  vector<MenuItem *> items;

public:
  Order() = default;
  void addItem(MenuItem *);
  void readInputs();
  double getTotalCost() const;
  void displayInvoice() const;
  /*
   * [**menuType**] is the name of the derived classes from MenuItem
   * They include: MainCourse, Appetizer, Dessert and Drink
   * But in our case we are asked to use this method on MainCourse only
   */
  void applyDiscount(const double &discount, const string &menuType);
};