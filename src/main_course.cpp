#include "../lib/main_course.h"
#include <iostream>
using namespace std;

MainCourse::MainCourse(string name, double price, int protein, string sideDish,
                       string cookingStyle)
    : MenuItem(name, price) {
  setProtein(protein);
  setSideDish(sideDish);
  setCookingStyle(cookingStyle);
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
  MenuItem::input();
  cout << "- Protein: ";
  cin >> protein;
  cout << "- Side dish: ";
  getline(cin, sideDish);
  cout << "- Cooking style: ";
  getline(cin, cookingStyle);
}

void MainCourse::display() const {
  MenuItem::display();
  cout << "- Price: " << calculatePrice() << "\n";
  cout << "- Protein: " << getProtein() << "\n";
  cout << "- Side dish: " << getSideDish() << "\n";
  cout << "- Cooking style: " << getCookingStyle() << "\n";
}

double MainCourse::calculatePrice() const {
  const double PROTEIN_PRICE_PER_KG = 10.0; // $10 per kg
  double basePrice = MenuItem::getPrice();
  double proteinCost =
      (protein / 1000.0) * PROTEIN_PRICE_PER_KG; // Convert g to kg
  return basePrice + proteinCost;
}
