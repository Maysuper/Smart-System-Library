#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"
#include "Book.h"
#include <vector>

using namespace std;

class Member : public User {
public:
    vector<Book> borrowedBooks;
    vector<Book> reservedBooks;

    Member(string userName, string userId, string password)
        : User(userName, userId, password) {
    }

    bool borrowBook(vector<Book>& library, int numBooks);
    void returnBook();
    void viewBorrowedAndReservedBooks();
    void reserveBook(vector<Book>& library);
    void displayInformation() override;
};

#endif // MEMBER_H