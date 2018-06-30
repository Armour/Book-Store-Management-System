#include "Admin.h"

extern Log rec;
extern Library lib;
extern string account;

void Admin::AddUser() { // Add new user
    system("cls");
    User newuser; // Define 'newuser' to User class
    string name, pwd;
    cout << "Please input the username that you want to register" << endl;
    cin >> name; // Input username
    for (size_t i = 0; i < lib.UserArray.size(); i++)
        if (lib.UserArray[i].GetUsername() == name) { // If find that username
            if (lib.UserArray[i].GetStatus() != 0) { // Check status, 0 for Not exist
                cout << "User already exist! " << endl;
                Sleep(1000);
                return;
            } else {
                cout << "Please input your password" << endl; // The case that user exist in User.txt but status is 0
                cin >> pwd; // Input password
                lib.UserArray[i].SetUsername(name);
                lib.UserArray[i].SetPassword(pwd);
                lib.UserArray[i].SetStatus(3); // Set information for the user whose status was 0
                cout << "Add user succsessfully!~ " << endl;
                Sleep(1000);
                cout << "Automatic quit after 3 seconds." << endl;
                Sleep(2000);
                rec.UserLog(account, name, "add", 0); // Update UserLog.txt with "add" operation
                PrintUserArray(); // Output user information to User.txt
                return;
            }
        }
    cout << "Please input your password" << endl; // The case that user doesn't exist in User.txt
    cin >> pwd;
    newuser.SetUsername(name);
    newuser.SetPassword(pwd);
    newuser.SetStatus(3);
    lib.UserArray.push_back(newuser); // Add newuser to lib.UserArray
    cout << "Add user succsessfully!~ " << endl;
    Sleep(1000);
    cout << "Automatic quit after 3 seconds." << endl;
    Sleep(2000);
    rec.UserLog(account, name, "add", 0); // Update UserLog.txt with "add" operation
    PrintUserArray(); // Output user information to User.txt
}

void Admin::DelUser() { // Delete old user
    system("cls");
    int choice;
    string name;
    cout << "Please input the username that you want to delete" << endl;
    cin >> name; // Input the username
    for (size_t i = 0; i < lib.UserArray.size(); i++)
        if (lib.UserArray[i].GetUsername() == name) { // If find that username
            if (lib.UserArray[i].GetStatus() != 0) { // Check status, 0 for Not exist
                cout << "Are you sure you want to delete this user? (press 1: continue, 0: quit)" << endl;
                cin >> choice;
                if (choice == 1) { // Make sure want to delete this user
                    lib.UserArray[i].SetStatus(0);
                    cout << "Delete user succsessfully!~ " << endl;
                } else cout << "Delete canceled . " << endl; // Cancel the delete operation
                Sleep(1000);
                cout << "Automatic quit after 3 seconds." << endl;
                Sleep(2000);
                rec.UserLog(account, name, "del", 0); // Update UserLog.txt with "del" operation
                PrintUserArray(); // Output user information to User.txt
                return;
            }
        }
    cout << "User not exist! " << endl; // Username not exist in User.txt or status equal to 0
    Sleep(1000);
}

void Admin::SetUser() { // Change user's status (like Customer, Staff, Administartor)
    system("cls");
    int choice;
    string name;
    cout << "Please input the username that you want to change status" << endl;
    cin >> name; // Input the username
    for (size_t i = 0; i < lib.UserArray.size(); i++)
        if (name == lib.UserArray[i].GetUsername()) { // If find that username
            if (lib.UserArray[i].GetStatus() != 0) { // Check status, 0 for Not exist
                cout << "Please input a number:  3 for Customer, 2 for Staff, 1 for Administartor, 0 for quit" << endl;
                cin >> choice;
                if (choice != 0) { // Make sure want to change this user's status
                    lib.UserArray[i].SetStatus(choice);
                    cout << "Change user status succsessfully!~ " << endl;
                } else cout << "Change canceled." << endl; // Cancel the change operation
                Sleep(1000);
                cout << "Automatic quit after 3 seconds." << endl;
                Sleep(2000);
                rec.UserLog(account, name, "set", choice); // Update UserLog.txt with "set" operation
                PrintUserArray(); // Output user information to User.txt
                return;
            }
        }
    cout << "User not exist! " << endl; // Username not exist in User.txt or status equal to 0
    Sleep(1000);
}

void Admin::ListUser() { // List all users' information
    system("cls");
    string temp;
    vector<string> Stat; // Vector of string, use to indicate the status of user
    temp = "Admin";
    Stat.push_back(temp);
    temp = "Staff";
    Stat.push_back(temp);
    temp = "Customer";
    Stat.push_back(temp);
    cout << "This is the list of all the user:" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|       Username      |    Password(without encryption)    |   Status   |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < lib.UserArray.size(); i++) // Output each user information
        if (lib.UserArray[i].GetStatus() != 0)
            cout << "|" << setw(21) << lib.UserArray[i].GetUsername() << "|" <<  setw(36) << lib.UserArray[i].GetPassword()
                << "|" << setw(12) << Stat[lib.UserArray[i].GetStatus() - 1] << "|" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Input 0 to exit" << endl;
    cin >> temp;
    while (temp != "0")
        cin >> temp;
}

void Admin::Interface(string username) { // Admin interface
    char command;
    int stop = 0;
    while (1) {
        system("cls");
        cout << "Welcome! " << username << " You are administartor~" << endl;
        cout << "Please choose what you want to do by input a character that list under " << endl;
        while (1) { // The operation list
            cout << "1 ----- Add new user" << endl;
            cout << "2 ----- Delete user" << endl;
            cout << "3 ----- Change user privilage" << endl;
            cout << "4 ----- Add new book" << endl;
            cout << "5 ----- Delete book" << endl;
            cout << "6 ----- Change book information" << endl;
            cout << "7 ----- List book (ALL)" << endl;
            cout << "8 ----- List book (By Category)" << endl;
            cout << "9 ----- List book (By Name)" << endl;
            cout << "* ----- Show more book information by ISBN number" << endl;
            cout << "& ----- List all users' information" << endl;
            cout << "$ ----- Lookup net profit" << endl;
            cout << "% ----- Change my password" << endl;
            cout << "0 ----- Exit;" << endl;
            cin >> command;
            if (command != '*' && command != '&' && command != '%' && command != '$' && (command < '0' || command > '9')) { // If command doesn't match input rule
                cout << endl << "Wrong!! You should input '*','&','%','$' or number between 0-9" << endl;
                cout << "Please repick an order :) " << endl; // Ask to input again
            } else break;
        }
        switch (command) {
            case '1':
                AddUser(); // Add new user
                break;
            case '2':
                DelUser(); // Delete old user
                break;
            case '3':
                SetUser(); // Change user's status (like Customer, Staff, Administartor)
                break;
            case '4':
                AddBook(); // Add new books
                break;
            case '5':
                DelBook(); // Delete some books
                break;
            case '6':
                SetBook(); // Change books' information
                break;
            case '7':
                ListBookAll(); // List all book
                break;
            case '8':
                ListBookByC(); // List book by category
                break;
            case '9':
                ListBookByN(); // List book by name
                break;
            case '*':
                BookInfor(); // See more information of one book
                break;
            case '%':
                ChangePsw(); // Change password
                break;
            case '$':
                ViewProfit(); // Lookup profit
                break;
            case '&':
                ListUser(); // List all users' information
                break;
            case '0':
                stop = 1;
                cout << "System will quit after 3 seconds " <<endl;
                Sleep(3000);
                break;
        }
        if (stop) break;
    }
}
