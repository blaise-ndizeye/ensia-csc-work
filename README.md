# Restaurant Menu System

A C++ implementation of a restaurant menu management system that handles different types of menu items including main courses, appetizers, desserts and drinks.

[View Assignment PDF](tutor_10.pdf)

## Classes Overview

### MenuItem (Base Class)

- Abstract base class for all menu items
- Contains common properties like name and price
- Defines virtual functions for input, display and price calculation

### MainCourse

- Inherits from MenuItem
- Properties:
  - Protein content
  - Side dish
  - Cooking style
  - Extra protein weight
  - Protein price per kg
- Price calculation includes base price plus extra protein costs

### Appetizer

- Inherits from MenuItem
- Properties:
  - Size (S/M/L)
  - Description
  - Vegetarian status

### Dessert

- Inherits from MenuItem
- Properties:
  - Flavor
  - Gluten-free status
- Price increases by 20% for gluten-free items

### Drink

- Inherits from MenuItem
- Properties:
  - Type
  - Serving size (ml)
  - Temperature (hot/cold)
- Price adjusts based on serving size and temperature

### Order

- Manages a collection of menu items
- Can add items, calculate total cost
- Displays invoice
- Applies discounts to specific menu types

## Usage Example

```cpp
int main() {
    // Create menu items
    Drink drinkObj("Coke", 2.50, "Soda", 350, "cold");
    MainCourse mc1("Steak", 15.00, 300, "Mashed Potatoes", "Medium Rare", 2, 8.79);
    Appetizer appetizerObj("Spring Rolls", 5.00, "Crispy vegetable rolls with dipping sauce", true);
    Dessert dessertObj("Cheesecake", 6.00, "New York Style", false);

    // Create order and add items
    Order orderObj;
    orderObj.addItem(&drinkObj);
    orderObj.addItem(&mc1);
    orderObj.addItem(&appetizerObj);
    orderObj.addItem(&dessertObj);

    // Display invoice
    orderObj.displayInvoice();

    return 0;
}
```

## Features

- Polymorphic menu item handling
- Price calculation based on item-specific attributes
- Input and display functionality for all items
- Order management with invoice generation
- Discount application system

## Implementation Details

- Uses virtual functions for polymorphic behavior
- Implements proper memory management
- Follows object-oriented design principles
- Supports console-based input/output
