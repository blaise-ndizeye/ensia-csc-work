#include "../lib/dessert.h"
#include <iostream>
using namespace std;

Dessert::Dessert(string name, double price, string flavor, bool glutenFree)
    : MenuItem(name, price) {
  setFlavor(flavor);
  setGlutenFree(glutenFree);
}

string Dessert::getFlavor() const { return flavor; }

void Dessert::setFlavor(const string &flavor) { this->flavor = flavor; }

bool Dessert::getGlutenFree() const { return glutenFree; }

void Dessert::setGlutenFree(const bool &glutenFree) {
  this->glutenFree = glutenFree;
}

void Dessert::input() {
  cout << "Input Dessert: \n";
  MenuItem::input();
  cout << "- Gluten Free (1 or 0): ";
  cin >> glutenFree;
  cin.ignore();
  cout << "- Flavor: ";
  getline(cin, flavor);
}

void Dessert::display() const {
  MenuItem::display();
  cout << "- Price: $" << calculatePrice() << "\n";
  cout << "- Flavor: " << getFlavor() << "\n";
  cout << "- Gluten Free: " << (getGlutenFree() ? "Yes" : "No") << "\n";
}

double Dessert::calculatePrice() const { return MenuItem::getPrice(); }