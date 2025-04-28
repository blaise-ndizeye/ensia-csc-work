#include "../lib/appetizer.h"
#include <iostream>
using namespace std;

Appetizer::Appetizer(string name, double price, string description,
                     bool vegeterian)
    : MenuItem(name, price) {
  setDescription(description);
  setVegeterian(vegeterian);
}

char Appetizer::getSize() const { return size; }

void Appetizer::seSize(const char &size) {
  char modifiedSize = toupper(size);

  if (modifiedSize != 'S' || modifiedSize != 'M' || modifiedSize != 'L') {
    throw invalid_argument("Invalid size. Size must be 'S', 'M' or 'L'!");

    this->size = modifiedSize;
  }
}

string Appetizer::getDescription() const { return description; }

void Appetizer::setDescription(const string &description) {
  this->description = description;
}

bool Appetizer::getVegeterian() const { return vegeterian; }

void Appetizer::setVegeterian(const bool &vegetarian) {
  this->vegeterian = vegetarian;
}

void Appetizer::input() {
  cout << "- Size (S, L, M): ";
  cin >> size;
  cout << "- Vegetarian (1 or 0): ";
  cin >> vegeterian;
  cout << "- Description: ";
  getline(cin, description);
}

void Appetizer::display() const {
  MenuItem::display();
  cout << "Size: " << getSize() << "\n";
  cout << "Vegeterian: " << (getVegeterian() ? "Yes" : "No") << "\n";
  cout << "Description: " << getDescription() << "\n";
  cout << "- Price: " << calculatePrice() << "\n";
}

double Appetizer::calculatePrice() const {
  double basePrice = MenuItem::getPrice();

  switch (size) {
  case 'S':
    return basePrice;

  case 'L':
    return basePrice + 0.5 * basePrice;

  case 'M':
    return basePrice + 0.8 * basePrice;

  default:
    throw invalid_argument("Invalid size. Size must be 'S', 'M' or 'L'!");
  }
}