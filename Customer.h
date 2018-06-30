#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Library.h"

class Customer : public User {
public:
    void BuyBook(); // Customer buy books
    void Refund(); // Customer ask for refund
    void Interface(string username); // Customer interface
};

#endif
