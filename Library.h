#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "User.h"

class Library {
public:
    void LoadUser(); // Load User.txt
    void LoadBook(); // Load Book.txt
    void LoadCash(); // Load Cash.txt
    void SetIncome(double new_income) { income = new_income; }; // Change income
    void SetOutcome(double new_outcome) { outcome = new_outcome; }; // Change outcome
    double GetIncome() { return income; };
    double GetOutcome() { return outcome; };
    vector<Book> BookArray; // Store all books in vector
    vector<User> UserArray; // Store all users in vector
private:
    double income; // Total income
    double outcome; // Total outcome
};

#endif
