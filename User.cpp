#include "User.h"
#include "Library.h"

extern Log rec;
extern Library lib;
extern string account;

void User::PrintUserArray() { // Output user information to User.txt
    ofstream fout;
    fout.open("User.txt"); // Open and cover User.txt
    if (!fout) { // If can't open
        cerr << "User.txt can't open" << endl;
        abort(); // Exit
    }
    for (size_t i = 0; i < lib.UserArray.size(); i++ ) // Output each user's information
        fout << lib.UserArray[i].GetUsername() << " " << lib.UserArray[i].GetPassword() << " " << lib.UserArray[i].GetStatus() << endl;
    fout.close(); // Close User.txt
}

void User::PrintBookArray() { // Output book information to Book.txt
    ofstream fout;
    fout.open("Book.txt"); // Open and cover Book.txt
    if  (!fout) { // If can't open
        cerr << "Book.txt can't open" << endl;
        abort(); // Exit
    }
    for (size_t i = 0; i < lib.BookArray.size(); i++ ) // Output each book's information
        fout << lib.BookArray[i].GetName() << " " << lib.BookArray[i].GetIsbn() << " " << lib.BookArray[i].GetAuthor()
            << " " << lib.BookArray[i].GetNumber() << " " << lib.BookArray[i].GetCategory()
            << " " << lib.BookArray[i].GetPrice() << " " << lib.BookArray[i].GetDiscount()
            << " " << lib.BookArray[i].GetDisc_num() << " " << lib.BookArray[i].GetInformation() << endl;
    fout.close(); // Close Book.txt
}

void User::PrintCash() { // Output cash information to Cash.txt
    ofstream fout;
    fout.open("Cash.txt"); // Open and cover Cash.txt
    if (!fout) { // If can't open
        cerr << "Cash.txt can't open" << endl;
        abort(); // Exit
    }
    fout << lib.GetIncome() << endl; // Output income
    fout << lib.GetOutcome() << endl; // Output outcome
    fout.close(); // Close Book.txt
}

 int User::IsAllDigit(const string& str) { // Check if str is all made of digital number
    int i ;
    for(i = 0; i != str.length(); i++)
        if (!isdigit(str[i]) && (str[i]!='.')) return 0; // '.' for double number
    return 1;
}

void User::ListBookAll() { // List all book
    system("cls");
    string temp;
    cout << "This is the list of all the book:" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|       ISBN       |             Name            | Number |    Price    |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < lib.BookArray.size(); i++) { // Output each book information
        cout << "|" << setw(18) << lib.BookArray[i].GetIsbn() << "|" <<  setw(29) << lib.BookArray[i].GetName() <<  "|"
            <<  setw(8) << lib.BookArray[i].GetNumber() << "|"<<  setw(13) << setiosflags(ios::fixed) << setprecision(2) <<lib.BookArray[i].GetPrice()  << "|" << endl;
    }
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Input 0 to exit" << endl;
    cin >> temp;
    while (temp != "0")
        cin >> temp;
}

void User::ListBookByC() { // List book by category
    system("cls");
    string temp, category;
    cout << "Please input the category that you want to list: " << endl;
    while (1) {
        cin >> category;
        if (IsAllDigit(category)) break;
        cout << "Pleass input a digital number :)   Try again." << endl;
    }
    system("cls");
    cout << "This is the list of all the book in category " << category << " :" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|       ISBN       |             Name            | Number |    Price    |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < lib.BookArray.size(); i++) // Output each book information in this category
        if (lib.BookArray[i].GetCategory() == stoi(category)) {
            cout << "|" << setw(18) << lib.BookArray[i].GetIsbn() << "|" <<  setw(29) << lib.BookArray[i].GetName() <<  "|"
                <<  setw(8) << lib.BookArray[i].GetNumber() << "|"<<  setw(13) << setiosflags(ios::fixed) << setprecision(2) <<lib.BookArray[i].GetPrice()  << "|" << endl;
    }
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Input 0 to exit" << endl;
    cin >> temp;
    while (temp != "0")
        cin >> temp;
}

void User::ListBookByN() { // List book by name
    system("cls");
    string temp, name;
    cout << "Please input the name that you want to find: " << endl;
    cin >> name;
    system("cls");
    cout << "This is the list of all the book that name contains string \"" << name << " \" :" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|       ISBN       |             Name            | Number |    Price    |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < lib.BookArray.size(); i++) // Output each book information match this name
        if (lib.BookArray[i].GetName().find(name) != string::npos) {
            cout << "|" << setw(18) << lib.BookArray[i].GetIsbn() << "|" <<  setw(29) << lib.BookArray[i].GetName() <<  "|"
                <<  setw(8) << lib.BookArray[i].GetNumber() << "|"<<  setw(13) << setiosflags(ios::fixed) << setprecision(2) <<lib.BookArray[i].GetPrice()  << "|" << endl;
        }
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Input 0 to exit" << endl;
    cin >> temp;
    while (temp != "0")
        cin >> temp;
}

void User::BookInfor() { // See more information of one book
    system("cls");
    string temp, isbn;
    cout << "Please input the ISBN number of the book that you want to find: " << endl;
    cin >> isbn;
    for (size_t i = 0; i < lib.BookArray.size(); i++)
        if (lib.BookArray[i].GetIsbn() == isbn ) { // If exist, list its detail information
            system("cls");
            cout << "Detail information of the book with ISBN number " << isbn << " : " << endl;
            cout << "Name            : " << lib.BookArray[i].GetName() << endl;
            cout << "Author            : " << lib.BookArray[i].GetAuthor() << endl;
            cout << "Number            : " << lib.BookArray[i].GetNumber() << endl;
            cout << "Category        : " << lib.BookArray[i].GetCategory() << endl;
            cout << "Price            : " << setiosflags(ios::fixed) << setprecision(2) << lib.BookArray[i].GetPrice() << endl;
            cout << "Discount        : " << setiosflags(ios::fixed) << setprecision(2) << lib.BookArray[i].GetDiscount()  << endl;
            cout << "Disc_num        : " << lib.BookArray[i].GetDisc_num() << endl;
            cout << "Information        : " << lib.BookArray[i].GetInformation() << endl;
            cout << endl;
            cout << "Input 0 to exit" << endl;
            cin >> temp;
            while (temp != "0")
                cin >> temp;
            return;
        }
    cout << "Not found this book! " << endl;
    Sleep(1000);
}

void User::ChangePsw() { // User choose to change his or her password
    system("cls");
    string temp, password;
    cout << "Please input the new password that you want: " << endl;
    cin >> password;
    cout << "Please repeat it: " << endl;
    cin >> temp;
    if (temp != password) { // If two input are not match then exit
        cout << "Two password doesn't match!! Change password failed... " << endl;
        Sleep(1500);
        return;
    } else {
        for (size_t i = 0; i < lib.BookArray.size(); i++)
            if (lib.UserArray[i].GetUsername() == account )
                lib.UserArray[i].SetPassword(password); // Change password
        cout << "Password change successfully !~~ " << endl;
        rec.UserLog(account, account, "psw", 0); // Update UserLog.txt with "psw" operation
        PrintUserArray(); // Output user information to User.txt
        Sleep(2000);
    }
}
