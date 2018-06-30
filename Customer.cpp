#include "Customer.h"

extern Log rec;
extern Library lib;
extern string account;

void Customer::BuyBook() { // Customer buy books
    system("cls");
    string isbn, temp;
    cout << "Please input the ISBN number of the book that you want to buy " << endl;
    cin >> isbn; // Input the ISBN number
    for (size_t i = 0; i < lib.BookArray.size(); i++)
        if (lib.BookArray[i].GetIsbn() == isbn) { // If find that ISBN number
            cout << "There are " << lib.BookArray[i].GetNumber() << " copies of this book, how many do you want to buy?  " << endl;
            while (1) {
                cin >> temp; // Input how many book customer want to buy
                if (IsAllDigit(temp)) break;
                cout << "Pleass input a digital number :)   Try again." << endl;
            }
            if (stoi(temp) > lib.BookArray[i].GetNumber()) { // If book is not enough for customer to buy
                cout << "Book number is not that much! " << endl;
                Sleep(1000);
            } else {
                lib.BookArray[i].SetNumber(lib.BookArray[i].GetNumber() - stoi(temp)); // Decrease the number of this book in lib.BookArray
                cout << "Buy " << stoi(temp) << " copies of that book, succsessfully!~ " << endl;
                Sleep(1000);
                cout << "Automatic quit after 3 seconds." << endl;
                Sleep(2000);
                rec.BookLog(account, isbn, "buy", stoi(temp)); // Update BookLog.txt with "buy" operation
                rec.CashLog(account, isbn, "buy", lib.BookArray[i].NetPrice(stoi(temp))); // Update CashLog.txt with "buy" operation
                PrintBookArray(); // Output book information to Book.txt
                PrintCash(); // Output cash information to Cash.txt
            }
            return;
        }
    cout << "Not found this book! " << endl; // Book not found in Book.txt
    Sleep(1000);
}

void Customer::Refund() { // Customer ask for refund
    system("cls");
    string isbn, temp;
    cout << "Please input the ISBN number of the book that you want to ask for refund " << endl;
    cin >> isbn; // Input the ISBN number
    for (size_t i = 0; i < lib.BookArray.size(); i++)
        if (lib.BookArray[i].GetIsbn() == isbn) { // If find that ISBN number
            cout << " How many copies of that book do you want toask for refund?  " << endl;
            while (1) {
                cin >> temp; // Input how many book customer want to refund
                if (IsAllDigit(temp)) break;
                cout << "Pleass input a digital number :)   Try again." << endl;
            }
            lib.BookArray[i].SetNumber(lib.BookArray[i].GetNumber() + stoi(temp)); // Increase the number of this book in lib.BookArray
            cout << "Refund " << stoi(temp) << " copies of that books, succsessfully!~ " << endl;
            Sleep(1000);
            cout << "Automatic quit after 3 seconds." << endl;
            Sleep(2000);
            rec.BookLog(account, isbn, "ref", stoi(temp)); // Update BookLog.txt with "buy" operation
            rec.CashLog(account, isbn, "ref", lib.BookArray[i].NetPrice(stoi(temp))); // Update CashLog.txt with "buy" operation
            PrintBookArray(); // Output book information to Book.txt
            PrintCash(); // Output cash information to Cash.txt
            return;
        }
    cout << "This is not our store's book! " << endl; // Book not found in Book.txt
    Sleep(1000);
}

void Customer::Interface(string username) { // Admin interface
    char command;
    int stop = 0;
    while (1) {
        system("cls");
        cout << "Welcome! " << username << " You are a customer~" << endl;
        cout << "Please choose what you want to do by input a number " << endl;
        while (1) { // The operation list
            cout << "1 ----- Buy book" << endl;
            cout << "2 ----- Refund" << endl;
            cout << "3 ----- List book (ALL)" << endl;
            cout << "4 ----- List book (By Category)" << endl;
            cout << "5 ----- List book (By Name)" << endl;
            cout << "6 ----- Show more book information by ISBN number" << endl;
            cout << "7 ----- Change my password" << endl;
            cout << "0 ----- Exit;" << endl;
            cin >> command;
            if (command < '0' || command > '7') {
                cout << endl << "Wrong!! You should input number between 0-7 " << endl;
                cout << "Please repick a number :) " << endl;
            } else break;
        }
        switch (command) {
            case '1':
                BuyBook(); // Customer buy books
                break;
            case '2':
                Refund(); // Customer ask for refund
                break;
            case '3':
                ListBookAll(); // List all book
                break;
            case '4':
                ListBookByC(); // List book by category
                break;
            case '5':
                ListBookByN(); // List book by name
                break;
            case '6':
                BookInfor(); // See more information of one book
                break;
            case '7':
                ChangePsw(); // Change password
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
