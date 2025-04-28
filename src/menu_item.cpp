#include "../lib/menu_item.h"
#include <iostream>
using namespace std;

MenuItem::MenuItem(string name, double price) : name(name) { setPrice(price); }

string MenuItem::getName() const { return name; }

void MenuItem::setName(const string &name) { this->name = name; }

double MenuItem::getPrice() const { return price; }

void MenuItem::setPrice(const double &price) {
  if (price <= 0)
    throw invalid_argument("Price must be greater than zero!");

  this->price = price;
}

void MenuItem::input() {
  cout << "- Name: ";
  getline(cin, name);
  cout << "- Price: ";
  cin >> price;
}

void MenuItem::display() const { cout << "- Name: " << name << "\n"; }