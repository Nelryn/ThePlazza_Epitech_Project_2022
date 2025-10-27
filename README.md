# ThePlazza Epitech Project 2022

A comprehensive pizzeria simulation demonstrating advanced concurrent programming concepts including multi-process architecture, thread management, inter-process communication, and load balancing.

---

## 🎯 Overview

The Plazza is an **advanced C++** project that simulates a pizzeria with multiple kitchens, each containing several cooks working simultaneously. The system manages order reception, load balancing across kitchens, ingredient stock management, and inter-process communication.
This was developed as a 3 man project:

* Process and thread management
* Inter-process communication (IPC)
* Synchronization mechanisms (mutex, conditional variables)
* Load balancing algorithms
* Object-oriented encapsulation of system resources

---

## Core Functionality

* **Interactive shell** for placing orders and monitoring system status
* **Dynamic kitchen creation** based on workload
* **Automatic load balancing** across multiple kitchens
* **Multi-threaded cooking** with thread pool management
* **Ingredient stock system** with automatic regeneration
* **Real-time status** monitoring of all kitchens and cooks
* **Pizza order logging** for tracking completed orders

---

## 🔨 Building

### Using Makefile

```bash
# Build the project
make

# Clean object files
make clean

# Full clean (remove binary)
make fclean

# Rebuild from scratch
make re
```

---

## 🚀 Usage

### Starting the Program

```bash
bash./plazza <multiplier> <cooks_per_kitchen> <restock_time>
```

#### Parameters:

* **multiplier**: Cooking time multiplier (float, can be 0-1 for faster cooking, >1 for slower)
* **cooks_per_kitchen**: Number of cook threads per kitchen (integer)
* **restock_time**: Time in milliseconds between ingredient restocking (integer)

#### Example:
```bash
./plazza 2 5 2000
```

This starts the pizzeria with:

* 2x cooking time multiplier
* 5 cooks per kitchen
* Ingredient restocking every 2000ms (2 seconds)

### Placing Orders

Orders must follow this grammar:

```bash
TYPE SIZE NUMBER [; TYPE SIZE NUMBER]*
```

#### Components:

* **TYPE**: Pizza name (Regina, Margarita, Americana, Fantasia)
* **SIZE**: S, M, L, XL, or XXL
* **NUMBER**: Quantity in format **x[1-99]**

#### Examples:

```bash
bashregina XXL x2
fantasia M x3; margarita S x1
americana L x5; regina M x2; fantasia XXL x1
```

### System Commands

```bash
bashstatus    # Display all kitchens status, cook occupancy, and ingredient stocks
exit      # Gracefully shut down the pizzeria
```

---

## 🍕 Pizza Menu

| Pizza          | Ingredients                                     | Cooking Time        |
| -------------- | ----------------------------------------------- | ------------------- |
| Margarita      | Dough, Tomato, Gruyere                          | 1 sec × multiplier  |
| Regina         | Dough, Tomato, Gruyere, Ham, Mushrooms          | 2 secs × multiplier |
| Americana      | Dough, Tomato, Gruyere, Steak                   | 2 secs × multiplier |
| Fantasia       | Dough, Tomato, Eggplant, Goat Cheese, Chef Love | 4 secs × multiplier |

### Pizza Sizes

* S (Small)
* M (Medium)
* L (Large)
* XL (Extra Large)
* XXL (Extra Extra Large)

---

## 📁 Project Structure

```bash
ThePlazza_Epitech_Project_2022/
├── src/                    # Source files
├── Makefile               # Build configuration
└── README.md              # This file
```
