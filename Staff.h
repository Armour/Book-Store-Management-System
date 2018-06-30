#ifndef STAFF_H
#define STAFF_H

#include "User.h"
#include "Library.h"

class Staff : public User {
public:
    void AddBook(); // Add new books
    void DelBook(); // Delete some books
    void SetBook(); // Change books' information
    void Interface(string username); // Staff interface
protected:
    void ViewProfit(); // Lookup net profit
};

#endif
