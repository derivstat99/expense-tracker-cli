#include <iostream>
#include <string>
#include "Tracker.h"

int main()
{
    Tracker tracker;
    tracker.loadFromFile();
    int choice;

    while (true)
    {
        std::cout << "\n1. Add Expense\n2. View Expenses\n3. Show Total\n4. Exit\n5.Filter by Category\n6.Filter by Date Range\n7.Sort by Date\n8.Delete By ID\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string name, date, note;
            double price;
            int catChoice, payChoice;

            std::cout << "Enter name: ";
            std::cin.ignore();
            getline(std::cin, name);

            std::cout << "Enter amount: ";
            std::cin >> price;

            std::cout << "Enter date (YYYY-MM-DD): ";
            std::cin >> date;

            std::cout << "Enter note: ";
            std::cin >> note;

            std::cout << "1. Food  2. Travel  3. Shopping  4. Other\n";
            std::cin >> catChoice;

            Category category;
            switch (catChoice)
            {
            case 1:
                category = Category::Food;
                break;
            case 2:
                category = Category::Travel;
                break;
            case 3:
                category = Category::Shopping;
                break;
            default:
                category = Category::Other;
            }

            std::cout << "1. Online  2. Cash\n";
            std::cin >> payChoice;

            PaymentMode paymentMode = (payChoice == 1) ? PaymentMode::Online : PaymentMode::Cash;

            Expense e(name, category, price, paymentMode, date, note);
            tracker.addExpense(e);
            tracker.appendToFile(e);
        }

        else if (choice == 2)
        {
            tracker.viewExpenses();
        }

        else if (choice == 3)
        {
            std::cout << "Total Expenses: " << tracker.getAllExpenses() << "\n";
        }

        else if (choice == 4)
        {
            break;
        }

        else if (choice == 5)
        {
            int catChoice;
            std::cout << "1. Food  2. Travel  3. Shopping  4. Other\n";
            std::cin >> catChoice;

            Category category;
            switch (catChoice)
            {
            case 1:
                category = Category::Food;
                break;
            case 2:
                category = Category::Travel;
                break;
            case 3:
                category = Category::Shopping;
                break;
            default:
                category = Category::Other;
            }
            tracker.filterByCategory(category);
        }

        else if (choice == 6)
        {
            std::string startDate, endDate;
            std::cout << "Enter the start date (YYYY-MM-DD): ";
            std::cin >> startDate;
            std::cout << "Enter the end date (YYYY-MM-DD): ";
            std::cin >> endDate;
            tracker.filterByDateRange(startDate, endDate);
        }

        else if (choice == 7)
        {
            tracker.sortByDate();
            std::cout << "Sorted by latest date\n";
        }

        else if (choice == 8)
        {
            int cid;
            std::cout << "Enter the Id to delete (Look up ID in View All Expenses): ";
            std::cin >> cid;
            tracker.deleteById(cid);
            std::cout << "Deleted Successfully!" << "\n";
        }
    }

    return 0;
}