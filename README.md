# Book-Store-Management-System

A simple but useful C++ program, assignment 1 in OOP course

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

### Installation Guide

1) Open all the .cpp and .h files in Visual Studio.
2) Compile the binaries and run the executable file.
3) The main file is "main.cpp".
4) Make sure all .txt files exist in the same folder with the .cpp and .h files, otherwise a error will occur.
5) Separate input words with an underline "_" instead of spaces.

#### Advanced features
Other than primitive features such as buying or selling books, the system provides the following features:
1) User rating system: users with different ratings have different privileges.
2) Log system: system admins can lookup the *Log.txt to view current changes.

### Class Design

**User Classes :**

    1) User     :    Fundamental class with primitive privileges, including listing books, viewing detailed information, and changing a password.
    2) Customer :    Inherit from "User" class that adds new functionality such as purchasing a book, and asking for refund. 
    3) Staff    :    Inherit from "User" class that adds new privileges, including adding new books, deleting a book, looking up net profit, and changing a book's **information**.
    4) Admin    :    Inherit from "Staff" class that grants access to adding new users, delete a user, listing users, and changing user status.

**Other Classes :**

    5) Book     :    Fundamental class with a book's information and basic book management functions.
    6) Log      :    This class contains functions for logging all executed operation to .txt.
    7) Library  :    This class is a container for storing information of books, students, and cash. The class also contains functions for reading information stored in .txt files and rewriting them back afterwards.
    8) Password :    This class contains functions related to password disposal.

#### Detail Information

~~~
Book :
    name            the book's title
    isbn            the book's ISBN number, which is the unique identifier of a book (not a copy)
    author          the name of the author. E.g. X.Zed.Amour
    category        the book's category number.   E.g. 1 maybe for Literature, 2 maybe for Computer
    number          the remaining amount of copies in book store
    price           the retail price of a book
    discount        the discount given to customers when they buy many copies
    disc_num        the minimum number of books to purchase to use the discount
    information     the detail information about this book

User/Customer/Staff/Admin :
    username        the user's username, which is a unique identifier  
    password        the user's password 
    status          the user's status, 1 for Customer, 2 for Staff, 3 for Admin, 0 for Non-existent

Library :
    BookArray        store all the books' information input from Book.txt
    UserArray        store all the students' information input from User.txt
    income           the total income up to now
    outcome          the total outcome up to now
~~~

More detailed information can be found in comments ~

#### Expected function in future

1) Encryption of user password function in the Password class.
2) Add lookup history function in User class.
3) Add reservation function in Customer class.
4) More....

// Expected to use pure C++ programming style instead of C/C++ mixed style :D
