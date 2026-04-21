#pragma once
#include <string>

enum class Category
{
    Food,
    Travel,
    Shopping,
    Other
};

enum class PaymentMode
{
    Online,
    Cash
};

class Expense
{
private:
    int id;
    static int nextId;
    std::string name;
    Category category;
    double price;
    PaymentMode paymentMode;
    std::string date;
    std::string note;

public:
    Expense(std::string name, Category category, double price,
            PaymentMode paymentMode, std::string date,
            std::string note = "Money spent!");

    std::string getName() const;
    double getPrice() const;
    std::string getDate() const;
    std::string getNote() const;
    Category getCategory() const;
    PaymentMode getPaymentMode() const;

    std::string payString(PaymentMode p) const;
    std::string typeString(Category c) const;

    void display() const;
    int getId() const;
};