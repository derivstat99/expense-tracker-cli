# Expense Tracker (C++ CLI)

## Overview

This is a command-line based expense tracker written in C++.
It allows users to add, store, and analyze daily expenses using simple terminal input.

The project focuses on practicing core C++ concepts like OOP, STL, file handling, and basic data processing.

---

## Features

* Add new expenses (name, amount, category, date, note)
* View all stored expenses
* Calculate total spending
* Filter expenses by category
* Filter expenses within a date range
* Sort expenses by date (latest first)
* Show last 5 transactions
* Show top 5 highest expenses
* Save and load data using CSV file

---

## Concepts Used

* Classes and Objects (Expense, Tracker)
* Encapsulation and member functions
* STL containers:

  * vector (store expenses)
  * priority_queue (top 5 expenses)
* Lambda functions (sorting)
* File handling (ifstream, ofstream)
* String parsing (stringstream)
* Enums (Category, PaymentMode)

---

## File Structure

* main.cpp → handles user input and menu
* Expense.h / Expense.cpp → expense class implementation
* Tracker.h / Tracker.cpp → logic for managing expenses
* expenses.csv → stored data

---

## How It Works

* Each expense is stored as an object of the Expense class
* Tracker class maintains:

  * list of all expenses
  * last 5 transactions
  * top 5 highest expenses (using min-heap)
* Data is saved in a CSV file and loaded at program start

---

## How to Run

Compile using:

g++ main.cpp Tracker.cpp Expense.cpp -o app

Run:

./app

---

## Limitations

* No input validation (wrong formats may break logic)
* CSV parsing assumes clean data (no commas in text)
* Overwrites file instead of appending (can be improved)
* No user authentication system

---

## Future Improvements

* Append-only file saving
* Multi-user support (separate files per user)
* Better input validation
* Sorting by other parameters
* Monthly summaries / analytics

---
