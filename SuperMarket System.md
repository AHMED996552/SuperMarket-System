# SuperMarket System - Software Documentation

**Version:** 1.0
**Author:** (Analysis of code from Super market.cpp)
**Date:** 12/19/2025

---

## 1. Introduction
The SuperMarket System is a console-based C++ application that simulates a simple supermarket's point-of-sale (POS) and inventory management system. It provides a dual-mode interface:

* **User Mode:** Allows customers to view available products, add products to a shopping cart, and generate a final receipt with a total cost.
* **Manager Mode:** A password-protected section that allows a manager to add new products to the store, edit existing product names, and update product prices.

The application runs entirely in the console and uses in-memory data storage, meaning all changes are lost when the program terminates.

---

## 2. System Architecture

* **Language:** C++
* **Platform:** Windows Console (due to the use of `<conio.h>` for the `getch()` function).
* **Data Storage:** In-memory global variables (C-style arrays and `std::vector`). There is no database or file-based persistence.

### Key Data Structures
* `string products[20]`: A fixed-size C-style array holding the names of the products.
* `int prices[20]`: A fixed-size C-style array holding the prices for each product. The index of a price corresponds to the index of a product in the products array.
* `int menu_size`: A global integer that tracks the current number of active products in the products and prices arrays.
* `name_manger`, `password_manger`: Hardcoded global variables that store the credentials for the primary manager.
* `vector<int> bag` (Global): **Note:** This global vector appears to be unused. A local vector of the same name is declared and used within the `buy_product()` function, shadowing this global variable.

---

## 3. Module & Function Breakdown
This section details the purpose and functionality of each key function in the application.

### 3.1. Main Execution

**`int main()`**
* **Purpose:** The main entry point and primary application loop.
* **Functionality:**
    1.  Displays a welcome screen and waits for user input (`getch()`).
    2.  Presents the main navigation menu: "User", "Maneger" (Manager), or "Exit".
    3.  Uses a switch statement to call `user_page()` or `manger_page()` based on user selection.
    4.  Loops until the user selects "Exit" (option 3).

### 3.2. User Mode Functions

**`void user_page()`**
* **Purpose:** Manages the customer-facing interface.
* **Functionality:**
    1.  Prompts the user to enter their name (this name is not used again).
    2.  Presents the user menu: "Show the menu", "Buy a product", or "Exit".
    3.  Calls `show_menu()` or `buy_product()` based on selection.
    4.  Loops until the user selects "Exit".

**`void show_menu()`**
* **Purpose:** A utility function to display all available products and their prices.
* **Functionality:**
    1.  Iterates from $i=0$ to `menu_size`.
    2.  Prints the product and price in the format: `(i+1)-[Product Name] [Price]`.

**`void buy_product()`**
* **Purpose:** Manages the user's shopping cart and receipt generation.
* **Functionality:**
    1.  Declares a local `vector<int> bag` to store the 1-based indices of the products the user wishes to buy.
    2.  Presents a sub-menu: "Add products to cart", "Show the reciept", or "Return to main".
    3.  **Case 1 (Add):**
        * Asks for the total number of products to buy. Clears the local bag.
        * Loops that many times, showing the menu and asking the user to select a product by its number.
        * Adds the selected product number to the bag vector.
    4.  **Case 2 (Receipt):**
        * Checks if the bag is empty. If it is, it informs the user and makes a recursive call to `buy_product()`.
        * If the bag is not empty, it iterates through the bag, calculates the total price, and prints a formatted receipt listing each item and its price. Prints the final Total.

### 3.3. Manager Mode Functions

**`void manger_page()`**
* **Purpose:** Handles the manager authentication portal.
* **Functionality:**
    1.  Presents the manager menu: "Create new Email", "Login", or "Return to main".
    2.  Calls `create()` or `login()` based on selection.

**`void create()`**
* **Purpose:** A workflow to simulate creating a new manager account.
* **Functionality:**
    1.  Asks for a new manager name, password, and years of experience.
    2.  **Validation:** Checks if experience $>=3$. If not, it rejects the application.
    3.  **Confirmation:** If experience is sufficient, it asks the user to re-enter the name and password.
    4.  If credentials match, it grants access by immediately calling `manger_process()`.
    5.  **Critical Limitation:** This function does not save the new credentials to the global `name_manger` or `password_manger` variables. The new account is not persistent and cannot be used to log in via the `login()` function.

**`void login()`**
* **Purpose:** Authenticates a manager.
* **Functionality:**
    1.  Prompts for a username and password.
    2.  Compares the input directly against the hardcoded global `name_manger` and `password_manger` variables.
    3.  If successful, calls `manger_process()`.

**`void manger_process()`**
* **Purpose:** The main dashboard for an authenticated manager.
* **Functionality:**
    1.  Presents the manager's action menu: "Add Element to menu", "Edit", or "Return to manger page".
    2.  Calls `add()` or `Edit()` based on selection.

**`void add()`**
* **Purpose:** Adds new products to the store's catalog.
* **Functionality:**
    1.  Prompts the manager for a new `menu_size`.
    2.  Validates that the new size is greater than the original size (9).
    3.  Loops `menu_size - 9` times, prompting for the new product's name and price.
    4.  Stores the new items in the products and prices arrays at the end of the existing list.
    5.  Calls `show_menu()` to display the updated list.

**`void Edit()`**
* **Purpose:** Modifies an existing product's name or price.
* **Functionality:**
    1.  Asks the manager if they want to "edit product" (name) or "edit price".
    2.  **Case 1 (Edit Name):**
        * Asks for the product number (1-based index) to edit.
        * Asks for the new product name.
        * Updates `products[choose-1]` with the new name.
    3.  **Case 2 (Edit Price):**
        * Asks for the product number (1-based index) to edit.
        * Asks for the new product price.
        * Updates `prices[choose-1]` with the new price.
    4.  Calls `show_menu()` to display the changes.

---

## 4. How to Compile and Run

1.  **Prerequisites:** A C++ compiler (e.g., g++, MinGW, or the MSVC compiler from Visual Studio).
2.  **Compilation (using g++):**
    `g++ "Super market.cpp" -o supermarket.exe`
3.  **Execution:**
    `./supermarket.exe`

*Note: Since the code uses `<conio.h>`, it is intended to be compiled and run on a Windows operating system.*

---

## 5. Known Issues & Limitations

1.  **No Data Persistence:** All data (newly added items, price changes, manager accounts) is stored in memory and is lost when the application is closed.
2.  **Insecure Credentials:** Manager credentials are hardcoded as plain text in the source code, which is a significant security risk.
3.  **Manager Creation Bug:** The `create()` function does not persist the new manager's credentials. A newly created manager can only access the system immediately after creation but cannot log in again later.
4.  **Fixed Array Size:** The system is limited to a maximum of 20 products due to the fixed size of the products and prices arrays.
5.  **Global Variable Shadowing:** The global `vector<int> bag` is unused and is shadowed by a local variable of the same name in `buy_product()`, which may cause confusion during maintenance.
6.  **Unsafe Recursion:** The `buy_product()` function calls itself if the user tries to view an empty receipt. This is an unconventional design that could lead to a stack overflow if repeated.
7.  **Minor Typos:** Several typos exist in the UI text (e.g., "Maneger", "reciept").