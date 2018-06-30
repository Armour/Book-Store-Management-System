#include "Log.h"
#include "Library.h"
#include "windows.h"

extern Library lib;

void Log::UserLog(string loginname, string username, string operation, int status) { // Add new information to UserLog.txt
    ofstream fout;
    fout.open("UserLog.txt", ios::app); // Open and append to UserLog.txt
    if (!fout) { // If can't open
        cerr << "UserLog.txt can't open" << endl;
        abort(); // Exit
    }
    SYSTEMTIME sys;
    GetLocalTime(&sys); // Get system time
    fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << " ]"; // Output system tiime
    if (operation == "add")
        fout << " Admin(" << loginname << ") add a new user(" << username << ")" << endl;
    else if (operation == "del")
        fout << " Admin(" << loginname << ") delete a user(" << username << ")" << endl;
    else if (operation == "set")
        fout << " Admin(" << loginname << ") set user(" << username << ")'s status to (" << status <<") " << endl;
    else if (operation == "psw")
        fout << " User(" << loginname << ") change his/her password " << endl;
    fout.close(); // Close UserLog.txt
}

void Log::BookLog(string loginname, string bookisbn, string operation, int number) { // Add new information to BookLog.txt
    ofstream fout;
    fout.open("BookLog.txt", ios::app); // Open and append to BookLog.txt
    if (!fout) { // If can't open
        cerr << "BookLog.txt can't open" << endl;
        abort(); // Exit
    }
    SYSTEMTIME sys;
    GetLocalTime(&sys); // Get system time
    fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << " ]"; // Output system tiime
    if (operation == "buy")
        fout << " Customer(" << loginname << ") buy books(ISBN:" << bookisbn << ") with " << number << " copy(s)" << endl;
    else if (operation == "ref")
        fout << " Customer(" << loginname << ") refund books(ISBN:" << bookisbn << ") with " << number << " copy(s)" << endl;
    else if (operation == "add")
        fout << " Manager(" << loginname << ") add new books(ISBN:" << bookisbn << ") with " << number << " copy(s)" << endl;
    else if (operation == "del")
        fout << " Manager(" << loginname << ") delete books(ISBN:" << bookisbn << ") with " << number << " copy(s)" << endl;
    else if (operation == "set")
        fout << " Manager(" << loginname << ") change book(ISBN:" << bookisbn << ")'s information " << endl;
    fout.close(); // Close BookLog.txt
}

void Log::CashLog(string loginname, string bookisbn, string operation, double money) { // Add new information to CashLog.txt
    ofstream fout;
    fout.open("CashLog.txt", ios::app); // Open and append to BookLog.txt
    if (!fout) { // If can't open
        cerr << "CashLog.txt can't open" << endl;
        abort(); // Exit
    }
    SYSTEMTIME sys;
    GetLocalTime(&sys); // Get system time
    fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << " ]"; // Output system tiime
    if (operation == "add") {
        fout << " Manager(" << loginname << ") add new books(ISBN:" << bookisbn << ") ---------- Outcome: " << money << endl;
        lib.SetOutcome(money + lib.GetOutcome());
    } else if (operation == "buy") {
        fout << " Customer(" << loginname << ") buy books(ISBN:" << bookisbn << ") ---------- Income: " << money << endl;
        lib.SetIncome(money + lib.GetIncome());
    } else if (operation == "ref") {
        fout << " Customer(" << loginname << ") refund books(ISBN:" << bookisbn << ") ---------- Outcome: " << money << endl;
        lib.SetOutcome(money + lib.GetOutcome());
    }
    fout.close(); // Close CashLog.txt
}
