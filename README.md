## Overview

*A Day in Someone's Life* is a console-based RPG and daily life simulation. Starting the morning with a bank account of 25,000 PKR, you set out into town to run errands, grab groceries, socialize with friends, enjoy amusement park rides, dine at popular local spots, and navigate unexpected twists before heading back home to sleep.

---

## Features

- **ATM & Banking System**
  - Withdraw cash on the go as you need it.
  - If your wallet runs dry while shopping or dining, take an automatic detour back to the ATM.
  - End-of-day deposit system with an option to keep pocket change.

- **Grocery & Fruit Markets**
  - Browse vegetable and fruit stalls with live itemized pricing.
  - Buy custom quantities with running bill calculations and detailed receipts.

- **Social Dilemmas & Companionship**
  - Run into your friend on the street!
  - Decide whether to invite him along (fair warning: you'll be covering tickets and meals for two!) or sneak off solo.

- **Fatima Jinnah Park**
  - Pick from classic rides: Slide, See-Saw, Ping, and Bumper Cars.
  - Dynamic ticket pricing based on whether you brought a friend.

- **Local Dining Experience**
  - Choose from authentic regional restaurants:
    - *Sialvi Madni Restaurant* (Lalamusa) — Chicken & Mutton Karahi
    - *Bismillah Burgers & Shawarma* (Lalamusa) — Shami Burgers & Shawarma
    - *Karachi Student Chicken Biryani* (Gujrat) — Biryani & Shami Tikki
    - *Kentucky Fried Chicken (KFC)* (Kharian) — Wings & Krunch Burgers
  - Order multiple dishes from multi-course menus.

- **Hospital Visit**
  - Too much park spinning right after heavy food? Experience nausea and visit the doctor for emergency meds and a checkup.

- **Night Cycle & Bedtime**
  - Return home, deposit leftover funds back into your account, and call it a day.

---

## Concepts Demonstrated

- **Data Structures**: Structs (`hotel`, `ride`, `veg`) to model items, prices, ratings, and locations.
- **State Management**: Managing persistent globals for cash-in-hand vs. bank balance.
- **Multidimensional Arrays**: Organizing menus and catalogs across different restaurant venues.
- **Control Flow**: Nested `do-while` loops, input validation, and decision branches.

---

## How to Build and Run

### Prerequisites
A standard C++ compiler (`g++`, `clang++`, or MSVC) supporting C++11 or later.

### Compilation
```bash
# Compile using g++ or clang++
g++ -std=c++11 Project.cpp -o day-in-life

# Run the game
./day-in-life
```

---

## Reflection

This project was built during the 1st semester of university as the capstone for **Programming Fundamentals**. It represents the initial steps of learning structured programming in C++, combining core algorithmic logic with a fun, relatable narrative. I think I got 9/10 for this project and it literally saved my semester.

