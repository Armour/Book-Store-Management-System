#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book {
public:
    // Get different information of Book
    string GetName() { return name; }
    string GetIsbn() { return isbn; }
    string GetAuthor() { return author; }
    int GetNumber() { return number; }
    int GetCategory() { return category; }
    double GetPrice() { return price; }
    double GetDiscount() { return discount; }
    int GetDisc_num() { return disc_num; }
    string GetInformation() { return information; }

    // Change different information of Book
    void SetName(string new_name) { name = new_name; }
    void SetIsbn(string new_isbn) { isbn = new_isbn; }
    void SetAuthor(string new_author) { author = new_author; }
    void SetNumber(int new_number) { number = new_number; }
    void SetCategory(int new_category) { category = new_category; }
    void SetPrice(double new_price) { price = new_price; }
    void SetDiscount(double new_discount) { discount = new_discount; }
    void SetDisc_num(int new_disc_num) { disc_num = new_disc_num; }
    void SetInformation(string new_imfor) { information = new_imfor; }

    // Calculate the money of buy (num) books
    double NetPrice(int num) {
        if (num > number)
            return ((double)num * price * discount);
        else
            return ((double)num * price);
    }
private:
    string name;
    string isbn; // ISBN number
    string author;
    int number; // The copy number of book
    int category; // The category number
    double price; // Unit-price of book
    double discount; // The discount that give to customer if him buy a lot of books
    int disc_num; // The at least number of book that customer can enjoy discount
    string information; // More commentary of that book
};

#endif
