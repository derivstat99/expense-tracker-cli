#include "Expense.h"
#include <iostream>

int Expense::nextId = 1;

Expense::Expense(std::string name, Category category, double price,
                 PaymentMode paymentMode, std::string date, std::string note)
    : id(nextId++), name(name), category(category), price(price),
      paymentMode(paymentMode), date(date), note(note) {}

std::string Expense::getName() const { return name; }
double Expense::getPrice() const { return price; }
std::string Expense::getDate() const { return date; }
std::string Expense::getNote() const { return note; }
Category Expense::getCategory() const { return category; }
PaymentMode Expense::getPaymentMode() const { return paymentMode; }

std::string Expense::payString(PaymentMode p) const
{
    return (p == PaymentMode::Online) ? "Online" : "Cash";
}

std::string Expense::typeString(Category c) const
{
    switch (c)
    {
    case Category::Food:
        return "Food";
    case Category::Shopping:
        return "Shopping";
    case Category::Travel:
        return "Travel";
    default:
        return "Other";
    }
}

void Expense::display() const
{
    std::cout << id << " | "
              << name << " | "
              << price << " | "
              << typeString(category) << " | "
              << payString(paymentMode) << " | "
              << date << " | "
              << note << std::endl;
}

int Expense::getId() const
{
    return id;
}