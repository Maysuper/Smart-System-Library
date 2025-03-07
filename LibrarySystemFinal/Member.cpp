#include "Member.h"

bool Member::borrowBook(vector<Book>& library, int numBooks) {
    try {
        if (numBooks < 1 || numBooks > 5) {
            throw LibraryException("Invalid borrow attempt: You can borrow between 1 to 5 books.");
        }

        if (borrowedBooks.size() + numBooks > 5) {
            throw LibraryException("Invalid borrow attempt: You cannot borrow more than 5 books total.");
        }

        for (int i = 0; i < numBooks; ++i) {
            string title;
            cout << "Enter book title to borrow: ";
            cin.ignore();
            getline(cin, title);
            bool bookFound = false;

            for (auto& book : library) {
                if (book.title == title && !book.reserved) {
                    int days;
                    cout << "Enter how many days you want to borrow this book? (Max 5): ";
                    cin >> days;
                    if (days < 1 || days > 5) {
                        throw LibraryException("You can borrow this book for a maximum of 5 days.");
                    }

                    borrowedBooks.push_back(Book(book.title, book.author, days));
                    book.reserved = true;
                    cout << "You have successfully borrowed: " << book.title << " for " << days << " days." << endl;
                    bookFound = true;
                    break;
                }
            }
            if (!bookFound) {
                throw LibraryException("Error: This book doesn't exist or is already reserved.");
            }
        }
    }
    catch (const LibraryException& e) {
        cout << "Error: " << e.what() << endl;
        return false;
    }
    return true;
}

void Member::returnBook() {
    string title;
    cout << "Enter the title of the book you want to return: ";
    cin.ignore();
    getline(cin, title);
    bool found = false;
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (it->title == title) {
            borrowedBooks.erase(it);
            cout << "You have successfully returned: " << title << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "The book was not found in your borrowed books." << endl;
    }
}

void Member::viewBorrowedAndReservedBooks() {
    if (borrowedBooks.empty() && reservedBooks.empty()) {
        cout << "You have not borrowed or reserved any books." << endl;
        return;
    }
    cout << "You have borrowed the following books:" << endl;
    for (const auto& book : borrowedBooks) {
        cout << "- " << book.title << " by " << book.author << " for " << book.days << " days" << endl;
    }
    cout << "\nYou have reserved the following books:" << endl;
    for (const auto& book : reservedBooks) {
        cout << "- " << book.title << " by " << book.author << " reserved for " << book.days << " day(s)" << endl;
    }
}

void Member::reserveBook(vector<Book>& library) {
    try {
        int numBooks;
        cout << "Enter how many books you want to reserve? (Max " << 5 << "): ";
        cin >> numBooks;

        if (numBooks < 1 || numBooks > 5) {
            throw LibraryException("You can reserve at most 5 books. Please try again.");
        }

        for (int i = 0; i < numBooks; ++i) {
            string title;
            int days;
            cout << "Enter book title to reserve: ";
            cin.ignore();
            getline(cin, title);
            bool bookFound = false;
            for (auto& book : library) {
                if (book.title == title && !book.reserved) {
                    while (true) {
                        cout << "Enter how many days you want to reserve this book? (Max 3): ";
                        cin >> days;
                        if (days < 1 || days > 3) {
                            cout << "Error: You can reserve the book for at most 3 days. Please try again." << endl;
                        }
                        else {
                            reservedBooks.push_back(Book(book.title, book.author, days, true));
                            book.reserved = true;
                            cout << "You have successfully reserved: " << book.title << " for " << days << " day(s)" << endl;
                            bookFound = true;
                            break;
                        }
                    }
                    break;
                }
            }
            if (!bookFound) {
                cout << "Error: This book doesn't exist or is already reserved. Please try again." << endl;
            }
        }
    }
    catch (const LibraryException& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void Member::displayInformation() {
    cout << "Member Name: " << userName << endl;
    cout << "Member ID: " << userId << endl;
}