#include "Tracker.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

void Tracker::addExpense(const Expense &e)
{
    expenses.push_back(e);
    total += e.getPrice();

    lastFive.push_back(e);
    if (lastFive.size() > 5)
    {
        lastFive.erase(lastFive.begin());
    }

    topFive.push({e.getPrice(), e});
    if (topFive.size() > 5)
    {
        topFive.pop();
    }
}

void Tracker::saveToFile() const
{
    std::ofstream file("expenses.csv");

    for (const auto &e : expenses)
    {
        file << e.getName() << ","
             << e.getPrice() << ","
             << e.typeString(e.getCategory()) << ","
             << e.payString(e.getPaymentMode()) << ","
             << e.getDate() << ","
             << e.getNote() << "\n";
    }
}

void Tracker::appendToFile(const Expense &e) const
{
    std::ofstream file("expenses.csv", std::ios::app);

    file << e.getName() << ","
         << e.getPrice() << ","
         << e.typeString(e.getCategory()) << ","
         << e.payString(e.getPaymentMode()) << ","
         << e.getDate() << ","
         << e.getNote() << "\n";
}

void Tracker::loadFromFile()
{
    std::ifstream file("expenses.csv");
    if (!file)
        return;

    std::string line;
    while (getline(file, line))
    {
        std::stringstream ss(line);

        std::string name, priceStr, categoryStr, paymentStr, date, note;

        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        getline(ss, categoryStr, ',');
        getline(ss, paymentStr, ',');
        getline(ss, date, ',');
        getline(ss, note, ',');

        double price = std::stod(priceStr);

        Category category;
        if (categoryStr == "Food")
            category = Category::Food;
        else if (categoryStr == "Travel")
            category = Category::Travel;
        else if (categoryStr == "Shopping")
            category = Category::Shopping;
        else
            category = Category::Other;

        PaymentMode paymentMode =
            (paymentStr == "Online") ? PaymentMode::Online : PaymentMode::Cash;

        expenses.emplace_back(name, category, price, paymentMode, date, note);
    }
}

void Tracker::viewExpenses() const
{
    for (const auto &e : expenses)
    {
        e.display();
    }
}

double Tracker::getAllExpenses() const
{
    return total;
}

void Tracker::filterByCategory(Category c)
{
    std::cout << "Filtered Results:\n";
    for (const auto &e : expenses)
    {
        if (e.getCategory() == c)
        {
            e.display();
        }
    }
}

void Tracker::filterByDateRange(const std::string &start, const std::string &end) const
{
    if (start > end)
    {
        std::cout << "Invalid Date Range!\n";
        return;
    }

    bool found = false;
    double durationPrice = 0;

    std::cout << "Queried purchases made between " << start << " and " << end << "\n";

    for (const auto &e : expenses)
    {
        if (e.getDate() >= start && e.getDate() <= end)
        {
            e.display();
            durationPrice += e.getPrice();
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No purchases made in the given dates range\n";
        return;
    }

    std::cout << "Amount spent: " << durationPrice << "\n";
}

void Tracker::sortByDate()
{
    std::sort(expenses.begin(), expenses.end(),
              [](const Expense &a, const Expense &b)
              {
                  return a.getDate() > b.getDate();
              });
}

void Tracker::showLastFive() const
{
    for (const auto &e : lastFive)
    {
        e.display();
    }
}

void Tracker::showTopFive()
{
    auto temp = topFive;

    while (!temp.empty())
    {
        temp.top().second.display();
        temp.pop();
    }
}

void Tracker::deleteById(int id)
{
    expenses.erase(
        std::remove_if(expenses.begin(), expenses.end(),
                       [id](const Expense &e)
                       { return e.getId() == id; }),
        expenses.end());

    rebuildState();
    saveToFile();
}

void Tracker::rebuildState()
{
    lastFive.clear();
    while (!topFive.empty())
    {
        topFive.pop();
    }
    for (const auto &e : expenses)
    {
        total += e.getPrice();

        lastFive.push_back(e);
        if (lastFive.size() > 5)
        {
            lastFive.erase(lastFive.begin());
        }

        topFive.push({e.getPrice(), e});
        if (topFive.size() > 5)
        {
            topFive.pop();
        }
    }
}