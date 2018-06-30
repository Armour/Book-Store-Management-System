# Book-Store-Management-System

A simple but useful  C++ program, assignment 1 in OOP course

## Welcome to SFU Book Store Management System

### Author Information

Name : Armour
E-mail : 497052684@qq.com

Please send me an e-mail if you meet some trouble with this system.

### File structure

~~~bash
____
    |.h
    |----
    |    |--Admin.h
    |    |--Book.h
    |    |--Customer.h
    |    |--Library.h
    |    |--Log.h
    |    |--Password.h
    |    |--Staff.h
    |    |--User.h
    |
    |.cpp
    |----
    |    |--Admin.cpp
    |    |--Customer.cpp
    |    |--Library.cpp
    |    |--Log.cpp
    |    |--Main.cpp
    |    |--Password.cpp
    |    |--Staff.cpp
    |    |--User.cpp
    |
    |.txt
    |----
    |    |--Book.txt
    |    |--BookLog.txt
    |    |--Cash.txt
    |    |--CashLog.txt
    |    |--User.txt
    |    |--UserLog.txt
    |
    |.md
    |----
         |--README.md
~~~

### How to use those files

1) Open all the .cpp and .h files in Visual Studio, compile and run it.
2) The main file is "main.cpp".
3) Make sure all .txt files are exist in the same folder with .cpp and .h files, otherwise it may output error.
4) Between each two words that you input, please use the underline "_" to replace space.

Advanced features (Beside book system like buy or sell books)
1) User rating system, user with different status have different power.
2) Log system, allow you to lookup the *Log.txt to know current changes.

### Classes Construction

**User Classes :**

    1) User     :    Fundamental class with basic authority like list book, see detail information or change password.
    2) Customer :    Inherit from "User", add new ability like buy book and ask for refund. 
    3) Staff    :    Inherit from "User", add new right like add new book, delete book, lookup net profit or change book's **information**.
    4) Admin    :    Inherit from "Staff", add new power like add new user, delete user, list users or change user's status.

**Other Classes :**

    5) Book     :    Fundamental class with book's information and some basic book management function.
    6) Log      :    This class has some functions used to log all the executed operation to .txt.
    7) Library  :    This class is a container to store all the information of books, students and cash, also it have some functions that can read information stored in .txt files and rewrite them back not after long.
    8) Password :    This class has some functions have connection with password disposal.

#### Detail Information

~~~
Book :
    name            the book's name
    isbn            the book's ISBN number, it's the unique mark of a book (not a copy)
    author          the person who wrote the book. E.g. X.Zed.Amour
    category        the book's category number.   E.g. 1 maybe for Literature, 2 maybe for Computer
    number          the amount of copies remained in book store
    price           the sells price of one book
    discount        the discount that give to customers when them buy many copies
    disc_num        the number of book at least that allow customers enjoy discount
    information     the more detail information about this book

User/Customer/Staff/Admin :
    username        the user's username, it's unique  
    password        the user's password 
    status          the user's status, 1 for Customer, 2 for Staff, 3 for Admin, 0 for Not exist

Library :
    BookArray        store all the books' information input from Book.txt
    UserArray        store all the students' information input from User.txt
    income           the total income up to now
    outcome          the total outcome up to now
~~~

More detail information can be found in comments ~

#### Expected function in future

1) Crypt user's password function in Class Password.
2) Add lookup history function in Class User.
3) Add reservation function in Class Customer.
4) More....

// Expected to use pure C++ programming style instead of C/C++ mixed style :D
