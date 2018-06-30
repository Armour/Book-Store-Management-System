#include <string>
#include <iostream>
#include <conio.h> // In order to use function _getch()

using namespace std;

class Password {
public:
    Password() {
        psw = ""; // Initial length to "";
        length = 0; // Initial length to 0
    }
    void InputPassword(); // Input password
    string GetPassword() { return psw; } // Return password
    // string CryptPassword(string password);
    ~Password() {};

private:
    string psw; // Store password
    int length; // The length of password
};
