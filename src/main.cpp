#include "../lib/appetizer.h"
#include "../lib/dessert.h"
#include "../lib/drink.h"
#include "../lib/main_course.h"
#include "../lib/order.h"

#include <iostream>
using namespace std;

int main() {
  Drink drinkObj("Coke", 2.50, "Soda", 350, "cold");

  MainCourse mc1("Steak", 15.00, 300, "Mashed Potatoes", "Medium Rare", 2,
                 8.79);
  MainCourse mc2("Grilled Salmon", 18.50, 250, "Steamed Vegetables",
                 "Well Done", 3.3, 12.99);
  MainCourse mc3("Chicken Breast", 13.75, 200, "Rice Pilaf", "Grilled", 5.2, 7);

  Appetizer appetizerObj('L', "Spring Rolls", 5.00,
                         "Crispy vegetable rolls with dipping sauce", true);

  Dessert dessertObj("Cheesecake", 6.00, "New York Style", false);

  Order orderObj;

  orderObj.addItem(&drinkObj);
  orderObj.addItem(&mc1);
  orderObj.addItem(&appetizerObj);
  orderObj.addItem(&mc2);
  orderObj.addItem(&dessertObj);
  orderObj.addItem(&mc3);

  cout << "Invoice Menu Items: \n";
  orderObj.displayInvoice();

  cout << "\nCustomize default values for Invoice Menu Items...\n";
  orderObj.readInputs();

  cout << "\nAppy 20% discount on all Main Course items...\n";
  orderObj.applyDiscount(0.2, " MainCourse");

  cout << "\nUpdate Invoice Menu Items: \n";
  orderObj.displayInvoice();

  return 0;
}