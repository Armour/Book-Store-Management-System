#include "Staff.h"

extern Library lib;
extern Log rec;
extern string account;

void Staff::AddBook() { // Add new books
    system("cls");
    Book newbook;
    string money, number, category, price, name, isbn, author, discount, disc_num, information;
    cout << "Please input the ISBN number of the book" << endl;
    cin >> isbn; // Input ISBN number of this new book
    for (size_t i = 0; i < lib.BookArray.size(); i++)
        if (lib.BookArray[i].GetIsbn() == isbn) {
            cout << "This ISBN number already exist =. =" << endl; // ISBN number already exist
            Sleep(1000);
            return;
        }
    cout << "Please input the name of the book" << endl;
    cin >> name; // Input bookname
    cout << "Please input the author of the book" << endl;
    cin >> author; // Input author
    cout << "Please input the copy number of the book" << endl;
    while (1) {
        cin >> number; // Input copy number
        if (IsAllDigit(number)) break;
        cout << "Pleass input a digital number :)   Try again." << endl;
    }
    cout << "Please input the category of the book" << endl;
    while (1) {
        cin >> category; // Input category number
        if (IsAllDigit(category)) break;
        cout << "Pleass input a digital number :)   Try again." << endl;
    }
    cout << "Please input the price of the book" << endl;
    while (1) {
        cin >> price; // Input price
        if (IsAllDigit(price)) break;
        cout << "Pleass input a digital number :)   Try again." << endl;
    }
    cout << "Please input the discount of the book" << endl;
    while (1) {
        cin >> discount; // Input discount
        if (IsAllDigit(discount)) break;
        cout << "Pleass input a digital number :)   Try again." << endl;
    }
    cout << "Please input the number of the book at least that can give a discount " << endl;
    while (1) {
        cin >> disc_num; // Input disc_num
        if (IsAllDigit(disc_num)) break;
        cout << "Pleass input a digital number :)   Try again." << endl;
    }
    cout << "Please input some information of this book" << endl;
    cin >> information; // Input detail information
    cout << "Please input the money that those book costs" << endl;
    while (1) {
        cin >> money; // Input the cost of those book
        if (IsAllDigit(money)) break;
        cout << "Pleass input a digital number :)   Try again." << endl;
    }
    newbook.SetName(name);
    newbook.SetIsbn(isbn);
    newbook.SetAuthor(author);
    newbook.SetNumber(stoi(number));
    newbook.SetCategory(stoi(category));
    newbook.SetPrice(stod(price));
    newbook.SetDiscount(stod(discount));
    newbook.SetDisc_num(stoi(disc_num));
    newbook.SetInformation(information);
    lib.BookArray.push_back(newbook); // Add this newbook to lib.BookArray
    cout << "Add book succsessfully!~ " << endl;
    Sleep(1000);
    cout << "Automatic quit after 3 seconds." << endl;
    Sleep(2000);
    rec.BookLog(account, isbn, "add", stoi(number)); // Update BookLog.txt with "add" operation
    rec.CashLog(account, isbn, "add", stod(money)); // Update CashLog.txt with "add" operation
    PrintBookArray(); // Output book information to Book.txt
    PrintCash(); // Output cash information to Cash.txt
}

void Staff::DelBook() { // Delete some books
    system("cls");
    string isbn, temp;
    cout << "Please input the ISBN number of the book that you want to delete " << endl;
    cin >> isbn; // Input ISBN number of the book that you want to delete
    for (size_t i = 0; i < lib.BookArray.size(); i++)
        if (lib.BookArray[i].GetIsbn() == isbn) {
            cout << "There are " << lib.BookArray[i].GetNumber() << " copies of this book, how many do you want to delete?  " << endl;
            while (1) {
                cin >> temp; // Input how many books you want to delete
                if (IsAllDigit(temp)) break;
                cout << "Pleass input a digital number :)   Try again." << endl;
            }
            if (stoi(temp) > lib.BookArray[i].GetNumber()) { // Book number is not enough to delete
                cout << "Book number is not that much! " << endl;
                Sleep(1000);
                cout << "Automatic quit after 3 seconds." << endl;
                Sleep(3000);
            } else {
                lib.BookArray[i].SetNumber(lib.BookArray[i].GetNumber() - stoi(temp)); // Change number of this book in lib.BookArray
                cout << "Delete (" << stoi(temp) << ") of this book succsessfully!~ " << endl;
                Sleep(1000);
                cout << "Automatic quit after 3 seconds." << endl;
                Sleep(2000);
                rec.BookLog(account, isbn, "del", stoi(temp)); // Update BookLog.txt with "del" operation
                PrintBookArray(); // Output book information to Book.txt
            }
            return;
        }
    cout << "Not found this book! " << endl; // Book not exist in Book.txt
    Sleep(1000);
}

void Staff::SetBook() { // Change books' information
    system("cls");
    int choice;
    string number, category, price, name, isbn, author, discount, disc_num, information;
    cout << "Please input the ISBN number of the book that you want to change the information." << endl;
    cin >> isbn; // Input ISBN number of the book that you want to change information
    for (size_t i = 0; i < lib.BookArray.size(); i++)
        if (lib.BookArray[i].GetIsbn() == isbn ) {
            cout << "Do you want to change the name of the book? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please input the new name of the book" << endl;
                cin >> name; // Input new bookname
                lib.BookArray[i].SetName(name);
            }
            cout << "Do you want to change the ISBN number of the book? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please input the new ISBN number of the book" << endl;
                cin >> isbn; // Input new ISBN number
                lib.BookArray[i].SetIsbn(isbn);
            }
            cout << "Do you want to change the author of the book? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please input the new author of the book" << endl;
                cin >> author; // Input new author
                lib.BookArray[i].SetAuthor(author);
            }
            /*cout << "Do you want to change the copy number of the book? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please input the new copy number of the book" << endl;
                while (1) {
                    cin >> number;
                    if (IsAllDigit(number)) break;
                    cout << "Pleass input a digital number :)   Try again." << endl;
                }
                lib.BookArray[i].SetNumber(stoi(number));
            }*/
            cout << "Do you want to change the category of the book? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please input the new category of the book" << endl;
                while (1) {
                    cin >> category; // Input new category number
                    if (IsAllDigit(category)) break;
                    cout << "Pleass input a digital number :)   Try again." << endl;
                }
                lib.BookArray[i].SetCategory(stoi(category));
            }
            cout << "Do you want to change the price of the book? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please input the new price of the book" << endl;
                while (1) {
                    cin >> price; // Input new price
                    if (IsAllDigit(price)) break;
                    cout << "Pleass input a digital number :)   Try again." << endl;
                }
                lib.BookArray[i].SetPrice(stod(price));
            }
            cout << "Do you want to change the discount of the book? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please input the new discount of the book" << endl;
                while (1) {
                    cin >> discount; // Input new discount
                    if (IsAllDigit(discount)) break;
                    cout << "Pleass input a digital number :)   Try again." << endl;
                }
                lib.BookArray[i].SetDiscount(stod(discount));
            }
            cout << "Do you want to change the disc_num of the book? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please input the new disc_num of the book" << endl;
                while (1) {
                    cin >> disc_num; // Input new disc_num
                    if (IsAllDigit(disc_num)) break;
                    cout << "Pleass input a digital number :)   Try again." << endl;
                }
                lib.BookArray[i].SetDisc_num(stoi(disc_num));
            }
            cout << "Do you want to change the information of the book? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please input the new information of the book" << endl;
                cin >> information; // Input new detail information
                lib.BookArray[i].SetInformation(information);
            }
            cout << "Change book information succsessfully!~ " << endl;
            Sleep(1000);
            cout << "Automatic quit after 3 seconds." << endl;
            Sleep(2000);
            rec.BookLog(account, isbn, "set", 0); // Update BookLog.txt with "set" operation
            PrintBookArray(); // Output book information to Book.txt
            return;
        }
    cout << "Not found this book! " << endl; // Book not exist in Book.txt
    Sleep(1000);
}

void Staff::ViewProfit() { // Lookup net profit
    system("cls");
    string temp;
    cout << "Total income: " << lib.GetIncome() << endl;
    cout << "Total outcome: " << lib.GetOutcome() << endl;
    cout << "Total net profit: " << lib.GetIncome() - lib.GetOutcome() << endl;
    cout << "Input 0 to exit" << endl;
    cin >> temp;
    while (temp != "0")
        cin >> temp;
    return;
}

void Staff::Interface(string username) { // Staff interface
    char command;
    int stop = 0;
    string str;
    while (1) {
        system("cls");
        cout << "Welcome! " << username << " You are staff~" << endl;
        cout << "Please choose what you want to do by input a number " << endl;
        while (1) { // The operation list
            cout << "1 ----- Add new book" << endl;
            cout << "2 ----- Delete book" << endl;
            cout << "3 ----- Change book information" << endl;
            cout << "4 ----- List book (ALL)" << endl;
            cout << "5 ----- List book (By Category)" << endl;
            cout << "6 ----- List book (By Name)" << endl;
            cout << "7 ----- Show more book information by ISBN number" << endl;
            cout << "8 ----- Lookup net profit" << endl;
            cout << "9 ----- Change my password" << endl;
            cout << "0 ----- Exit;" << endl;
            cin >> command;
            if (command < '0' || command > '9') { // If command doesn't match input rule
                cout << endl << "Wrong!! You should input number between 0-9 " << endl;
                cout << "Please repick a number :) " << endl; // Ask to input again
            } else break;
        }
        switch (command) {
            case '1':
                AddBook(); // Add new books
                break;
            case '2':
                DelBook(); // Delete some books
                break;
            case '3':
                SetBook(); // Change books' information
                break;
            case '4':
                ListBookAll(); // List all book
                break;
            case '5':
                ListBookByC(); // List book by category
                break;
            case '6':
                ListBookByN(); // List book by name
                break;
            case '7':
                BookInfor(); // See more information of one book
                break;
            case '8':
                ViewProfit(); // Lookup profit
                break;
            case '9':
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
