#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <vector>
#include "Member.h"
#include "Librarian.h"
#include "Administrator.h"
#include "Book.h"

using namespace std;

class LibrarySystem {
private:
    vector<Member> members;
    vector<Librarian> librarians;
    vector<Administrator> admins;
    vector<Book> library;

public:
    LibrarySystem();
    void AddBook(const string& title, const string& author);
    void RemoveBook(const string& title);
    void UpdateBook(const string& oldTitle, const string& newTitle);
    void DisplayBooks();
    void RemoveMember(const string& memberID);
    void RemoveLibrarian(const string& librarianID);
    void DisplayUsers();
    void RegisterMember();
    void RegisterLibrarian();
    User* login(const string& userType);
    void start();
    void AdminMenu(Administrator* admin);
    string hashPassword(const string& password); // Hashing function
    void DisplayMainMenu(); // Display main menu
};

#endif // LIBRARY_SYSTEM_H