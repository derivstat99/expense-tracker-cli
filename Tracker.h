#pragma once
#include "Expense.h"
#include <vector>
#include <queue>

class Tracker
{
private:
    double total;
    std::vector<Expense> expenses;
    std::vector<Expense> lastFive;
    std::priority_queue<std::pair<double, Expense>, std::vector<std::pair<double, Expense>>, std::greater<>> topFive;

public:
    void addExpense(const Expense &);
    void viewExpenses() const;
    void loadFromFile();
    void saveToFile() const;
    double getAllExpenses() const;
    void filterByDateRange(const std::string &start, const std::string &end) const;
    void filterByCategory(Category c);
    void sortByDate();
    void showTopFive();
    void showLastFive() const;
};