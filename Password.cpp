#include "Password.h"

void Password::InputPassword() { // Input password
    char temp_c;
    psw = "";
    while (true) {
        temp_c = _getch(); // Get a character without showing it
        if(temp_c != char(13)) { // If character is ENTER then break
            switch (temp_c) {
                case 8: // If character is Backspace
                    if (length != 0) {
                        cout << "\b \b";
                        psw = psw.substr(0, length-1);
                        length--;
                    }
                    break;
                default:
                    cout << "*"; // Use '*' to replace what you input
                    psw += temp_c; // Connect each character to string 'psw'
                    length++;
                    break;
            }
        } else break;
    }
    cout << endl;
}
