#include "../lib/order.h"
#include "../lib/main_course.h"
#include <iostream>
using namespace std;

void Order::addItem(MenuItem *item) { items.push_back(item); }

double Order::getTotalCost() const {
  double totalCost = 0.0;

  for (auto &item : items) {
    totalCost += item->calculatePrice();
  }
  return totalCost;
}

void Order::displayInvoice() const {
  for (auto &item : items) {
    item->display();
    cout << "\n _________________ \n";
  }
  cout << "Total cost: $" << getTotalCost() << "\n";
}

void Order::applyDiscount(const double &discount, const string &menuType) {
  cout << "\nMenuItem: Old -> New \n";

  for (auto &item : items) {
    MainCourse *mc = dynamic_cast<MainCourse *>(item);

    if (mc != nullptr) {
      double oldProteinPricePerKg = mc->getProteinPricePerKg();
      double discountedProteinPerKgPrice =
          oldProteinPricePerKg - oldProteinPricePerKg * discount;

      mc->setProteinPricePerKg(discountedProteinPerKgPrice);

      cout << "- " << item->getName() << ": " << oldProteinPricePerKg << " -> "
           << discountedProteinPerKgPrice << "\n";
    }
  }

  cout << "New total cost: $" << getTotalCost() << "\n";
}

void Order::readInputs() {
  for (auto &item : items) {
    item->input();
  }
}
