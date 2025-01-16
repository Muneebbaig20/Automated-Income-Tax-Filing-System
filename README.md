# Car Dealership Management System

## Overview

The **Car Dealership Management System** is a C++ based application that manages a car dealership's inventory. It allows both admin and users to interact with the system for adding, searching, and purchasing cars. Admins can add cars to the inventory, and users can search for cars within their budget or based on price range. The system also handles order processing and invoice generation.

## Features

- **Admin Features:**
  - Add cars to the inventory.
  - Display the inventory list.
  - View orders placed by users.
  
- **User Features:**
  - Search cars by price range or budget.
  - Select cars to purchase based on available budget.
  - View a summary of the selected cars and the total price.
  - Generate invoice after purchasing the cars.

- **Invoice Generation:**
  - The system generates invoices that include the car prices, taxes, and the remaining budget of the user.
  
- **Price Calculation:**
  - Cars have prices that fluctuate depending on the market.
  - Tax rates vary based on the total price of the selected cars.


### Explanation of OOP Pillars in the Code:
1. **Encapsulation**: 
   - The `Allcars`, `User`, and `CarInventory` classes encapsulate their data within private members and provide public getter and setter functions for safe access and modification.

2. **Inheritance**:
   - The `CarInventory` class inherits from `Allcars` to extend the functionality and add more specific behavior for managing cars in the inventory.

3. **Polymorphism**:
   - The `show()` method in the `Allcars` class overrides the abstract method in the `Display` interface. This demonstrates how objects of different types can be handled through a common interface.

4. **Abstraction**:
   - The `Display` class provides an abstract method `show()`, which is implemented by the `Allcars` class. This hides the complexity of displaying car details and allows users to interact with the system at a higher level.


## Requirements

- C++ Compiler (e.g., GCC, Clang, MSVC)
- Standard C++ libraries (iostream, string, vector, fstream)

