#include "Log.h"
#include "Book.h"
#include "User.h"
#include "Staff.h"
#include "Admin.h"
#include "Library.h"
#include "Customer.h"
#include "Password.h"

Log rec;
Library lib;
Password pwd;
string account;

int Login(string username, string password) { // Get user's status
    for (size_t i = 0; i < lib.UserArray.size(); i++ )
        if (username == lib.UserArray[i].GetUsername() && password == lib.UserArray[i].GetPassword()) // If find username and password in User.txt
            return lib.UserArray[i].GetStatus(); // Return status
    return 0;
}

void LoadData() { // Load all data from .txt
    lib.LoadUser(); // Load User.txt
    lib.LoadBook(); // Load Book.txt
    lib.LoadCash(); // Load Cash.txt
}

void Welcome() { // Welcome interface
    system("cls");
    int status = 0;
    int time = 0;
    cout << "Welcome to SFU Book Store Management System :D " << endl;
    cout << "Please login first~" << endl;
    while (status == 0) {
        cout << "Username: " << endl;
        cin >> account; // Input username
        cout << "Password: " << endl;
        pwd.InputPassword(); // Input password without showing what you input
        if (account == "blue" && pwd.GetPassword() == "shit") return; // XD
        status = Login(account, pwd.GetPassword()); // Get user's status
        if (status < 1 || status > 3) {
            time++; // Try how many times
            if (time < 3) cout << "Oops! Login fail :(     Please try again.. " << endl;
            else if (time < 4) cout << "Are you sure you remember the password? = =   (Try again... " << endl;
            else if (time < 5) cout << "Oh My God ... give you one last chance.." << endl;
            else {
                cout << "Maybe you should register a new account = =" << endl; // Failed too many times, force to exit
                Sleep(1500);
                return;
            }
            Sleep(1500);
        } else { // Choose interface depend on status
            if (status == 1) {
                Admin man;
                man.Interface(account);
            } else if (status == 2) {
                Staff man;
                man.Interface(account);
            } else if (status == 3) {
                Customer man;
                man.Interface(account);
            }
            break;
        }
        system("cls");
        cout << "Welcome to SFU Book Store Management System :D " << endl;
        cout << "Please login first~" << endl;
    }
}

int main(void) {
    LoadData(); // Load all data from .txt
    Welcome(); // Welcome interface
}
