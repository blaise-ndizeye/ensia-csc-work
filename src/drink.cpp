#include "../lib/drink.h"
#include <iostream>
using namespace std;

Drink::Drink(string name, double price, string type, int servingSize,
             string temperature)
    : MenuItem(name, price) {
  setType(type);
  setServingSize(servingSize);
  setTemperature(temperature);
}

string Drink::getType() const { return type; }

void Drink::setType(const string &type) { this->type = type; }

int Drink::getServingSize() const { return servingSize; }

void Drink::setServingSize(const int &servingSize) {
  this->servingSize = servingSize;
}

string Drink::getTemperature() const { return temperature; }

void Drink::setTemperature(const string &temperature) {
  this->temperature = temperature;
}

void Drink::input() {
  cout << "Input Drink: \n";
  MenuItem::input();
  cin.ignore();
  cout << "- Type: ";
  getline(cin, type);
  cout << "- Serving size (ml): ";
  cin >> servingSize;
  cin.ignore();
  cout << "- Temperature (hot/cold): ";
  getline(cin, temperature);
}

void Drink::display() const {
  MenuItem::display();
  cout << "- Price: $" << calculatePrice() << "\n";
  cout << "- Type: " << getType() << "\n";
  cout << "- Serving size: " << getServingSize() << "ml\n";
  cout << "- Temperature: " << getTemperature() << "\n";
}

double Drink::calculatePrice() const { return MenuItem::getPrice(); }