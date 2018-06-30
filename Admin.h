#ifndef ADMIN_H
#define ADMIN_H

#include "Staff.h"

class Admin : public Staff {
  public:
    void AddUser(); // Add new user
    void DelUser(); // Delete old user
    void SetUser(); // Change user's status (like Customer, Staff, Administartor)
    void Interface(string username); // Admin interface
  private:
    void ListUser(); // List all users' information
};

#endif
