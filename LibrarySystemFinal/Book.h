#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    int days;
    bool reserved;

    Book(string title, string author, int days = 0, bool reserved = false);
};

#endif // BOOK_H