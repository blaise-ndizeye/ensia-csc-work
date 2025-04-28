#include "../lib/main_course.h"
#include <iostream>
using namespace std;

MainCourse::MainCourse(string name, double price, int protein, string sideDish,
                       string cookingStyle, double extraProteinWeight,
                       double proteinPricePerKg)
    : MenuItem(name, price) {
  setProtein(protein);
  setSideDish(sideDish);
  setCookingStyle(cookingStyle);
  setProteinPricePerKg(proteinPricePerKg);
  setExtraProteinWeight(extraProteinWeight);
}

double MainCourse::getExtraProteinWeight() const { return extraProteinWeight; }

void MainCourse::setExtraProteinWeight(const double &extraProteinWeight) {
  this->extraProteinWeight = extraProteinWeight;
}

double MainCourse::getProteinPricePerKg() const { return proteinPricePerKg; }

void MainCourse::setProteinPricePerKg(const double &proteinPricePerKg) {
  this->proteinPricePerKg = proteinPricePerKg;
}

int MainCourse::getProtein() const { return protein; }

void MainCourse::setProtein(const int &protein) { this->protein = protein; }

string MainCourse::getSideDish() const { return sideDish; }

void MainCourse::setSideDish(const string &sideDish) {
  this->sideDish = sideDish;
}

string MainCourse::getCookingStyle() const { return cookingStyle; }

void MainCourse::setCookingStyle(const string &cookingStyle) {
  this->cookingStyle = cookingStyle;
}

void MainCourse::input() {
  cout << "Input Main Course: \n";
  MenuItem::input();
  cout << "- Protein: ";
  cin >> protein;
  cout << "- Side dish: ";
  cin.ignore();
  getline(cin, sideDish);
  cout << "- Cooking style: ";
  getline(cin, cookingStyle);
  // Implement inputs for extraProteinWeight & proteinPricePerKg if necessary
}

void MainCourse::display() const {
  MenuItem::display();
  cout << "- Price: $" << calculatePrice() << "\n";
  cout << "- Protein: " << getProtein() << "\n";
  cout << "- Side dish: " << getSideDish() << "\n";
  cout << "- Cooking style: " << getCookingStyle() << "\n";
  cout << "- Extra protein weight: " << getExtraProteinWeight() << "Kg\n";
  cout << "- Protein price per Kg: $" << getProteinPricePerKg() << "\n";
}

double MainCourse::calculatePrice() const {
  double basePrice = MenuItem::getPrice();
  return basePrice + (getExtraProteinWeight() * getProteinPricePerKg());
}
