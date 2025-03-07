#include "LibrarySystem.h"

LibrarySystem::LibrarySystem() {
    // Initialize some books.
    library.push_back(Book("Code Complete", "Steve McConnell"));
    library.push_back(Book("Design Patterns", "Erich Gamma"));
    library.push_back(Book("The Art of Computer Programming", "Donald Knuth"));
    library.push_back(Book("Clean Code", "Robert C. Martin"));
    library.push_back(Book("Refactoring", "Martin Fowler"));

    // Add some sample users.
    members.push_back(Member("Maye", "M01", "secreto"));
    members.push_back(Member("Bryan", "M02", "secreto2"));
    librarians.push_back(Librarian("Nata", "L01", "california"));
    admins.push_back(Administrator("Daira", "A01", "londres"));
}

void LibrarySystem::AddBook(const string& title, const string& author) {
    cout << "[DEBUG] Adding book: " << title << " by " << author << endl; // Logging
    library.push_back(Book(title, author));
    cout << "Book added successfully: " << title << " by " << author << endl;
}

void LibrarySystem::RemoveBook(const string& title) {
    bool found = false;
    for (auto it = library.begin(); it != library.end(); ++it) {
        if (it->title == title) {
            library.erase(it);
            cout << "Book removed successfully: " << title << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found: " << title << endl;
    }
}

void LibrarySystem::UpdateBook(const string& oldTitle, const string& newTitle) {
    bool found = false;
    for (auto& book : library) {
        if (book.title == oldTitle) {
            book.title = newTitle;
            cout << "Book title updated from " << oldTitle << " to " << newTitle << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found: " << oldTitle << endl;
    }
}

void LibrarySystem::DisplayBooks() {
    if (library.empty()) {
        cout << "No books in the library." << endl;
    }
    else {
        cout << "Library Books:" << endl;
        for (const auto& book : library) {
            cout << "- " << book.title << " by " << book.author;
            if (book.reserved) {
                cout << " [Reserved]";
            }
            cout << endl;
        }
    }
}

void LibrarySystem::RemoveMember(const string& memberID) {
    bool found = false;
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->userId == memberID) {
            members.erase(it);
            cout << "Member removed successfully: " << memberID << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Member not found: " << memberID << endl;
    }
}

void LibrarySystem::RemoveLibrarian(const string& librarianID) {
    bool found = false;
    for (auto it = librarians.begin(); it != librarians.end(); ++it) {
        if (it->userId == librarianID) {
            librarians.erase(it);
            cout << "Librarian removed successfully: " << librarianID << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Librarian not found: " << librarianID << endl;
    }
}

void LibrarySystem::DisplayUsers() {
    cout << "\nMembers:" << endl;
    for (const auto& member : members) {
        cout << " - " << member.userName << " (ID: " << member.userId << ")" << endl;
    }
    cout << "Librarians:" << endl;
    for (const auto& librarian : librarians) {
        cout << " - " << librarian.userName << " (ID: " << librarian.userId << ")" << endl;
    }
    cout << "Administrators:" << endl;
    for (const auto& admin : admins) {
        cout << " - " << admin.userName << " (ID: " << admin.userId << ")" << endl;
    }
}

void LibrarySystem::RegisterMember() {
    string memberID, name, password;
    cout << "Enter Member ID: ";
    cin >> memberID;

    if (memberID.empty()) {
        cout << "Error: Member ID cannot be empty." << endl;
        return;
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    if (name.empty()) {
        cout << "Error: Name cannot be empty." << endl;
        return;
    }

    cout << "Enter Password: ";
    cin >> password;
    if (password.length() < 6) {
        cout << "Error: Password must be at least 6 characters long." << endl;
        return;
    }

    string hashedPass = hashPassword(password);
    Member newMember(name, memberID, password);
    members.push_back(newMember);
    cout << "Simulated file write: " << memberID << " " << name << " " << hashedPass << endl;
    cout << "Member registered successfully!" << endl;
}

void LibrarySystem::RegisterLibrarian() {
    string librarianID, name, password;
    cout << "Enter Librarian ID: ";
    cin >> librarianID;

    if (librarianID.empty()) {
        cout << "Error: Librarian ID cannot be empty." << endl;
        return;
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    if (name.empty()) {
        cout << "Error: Name cannot be empty." << endl;
        return;
    }

    cout << "Enter Password: ";
    cin >> password;
    if (password.length() < 6) {
        cout << "Error: Password must be at least 6 characters long." << endl;
        return;
    }

    string hashedPass = hashPassword(password);
    Librarian newLibrarian(name, librarianID, password);
    librarians.push_back(newLibrarian);
    cout << "Simulated file write: " << librarianID << " " << name << " " << hashedPass << endl;
    cout << "Librarian registered successfully!" << endl;
}

User* LibrarySystem::login(const string& userType) {
    string userName, userId, password;
    cout << "Enter User Name: ";
    cin >> userName;
    cout << "Enter User ID: ";
    cin >> userId;
    cout << "Enter Password: ";
    cin >> password;

    if (userType == "Member") {
        for (auto& member : members) {
            if (member.userName == userName && member.userId == userId && member.password == password) {
                cout << "Welcome, " << userName << "!" << endl;
                return &member;
            }
        }
    }
    else if (userType == "Librarian") {
        for (auto& librarian : librarians) {
            if (librarian.userName == userName && librarian.userId == userId && librarian.password == password) {
                cout << "Welcome, " << userName << "!" << endl;
                return &librarian;
            }
        }
    }
    else if (userType == "Administrator") {
        for (auto& admin : admins) {
            if (admin.userName == userName && admin.userId == userId && admin.password == password) {
                cout << "Welcome, " << userName << "!" << endl;
                return &admin;
            }
        }
    }
    throw LibraryException("Invalid credentials!");
}

string LibrarySystem::hashPassword(const string& password) {
    return "hashed_" + password; // Simple hashing for demonstration purposes
}

void LibrarySystem::DisplayMainMenu() {
    cout << "\n===== Smart Library Management System =====" << endl;
    cout << "1. Login as Member" << endl;
    cout << "2. Login as Librarian" << endl;
    cout << "3. Login as Administrator" << endl;
    cout << "4. Register as Member (Type 'RegisterMember')" << endl;
    cout << "5. Register as Librarian (Type 'RegisterLibrarian')" << endl;
    cout << "Type 'exit' to quit the program." << endl;
}

void LibrarySystem::start() {
    while (true) {
        try {
            DisplayMainMenu();
            string input;
            cout << "\nEnter your choice: ";
            cin >> input;
            if (input == "exit") {
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            }
            else if (input == "RegisterMember") {
                RegisterMember();
                continue;
            }
            else if (input == "RegisterLibrarian") {
                RegisterLibrarian();
                continue;
            }

            int choice = stoi(input);
            string userType;
            if (choice == 1) userType = "Member";
            else if (choice == 2) userType = "Librarian";
            else if (choice == 3) userType = "Administrator";
            else {
                cout << "Invalid choice! Please try again." << endl;
                continue;
            }

            User* user = login(userType);
            user->displayInformation();
            // Handle user operations like borrowing, returning, etc.
            if (userType == "Member") {
                Member* member = static_cast<Member*>(user);
                while (true) {
                    int option;
                    cout << "\n===== Member Menu =====" << endl;
                    cout << "1. Borrow a Book" << endl;
                    cout << "2. Return a Book" << endl;
                    cout << "3. Reserve a Book" << endl;
                    cout << "4. View Borrowed and Reserved Books" << endl;
                    cout << "5. Exit to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> option;

                    try {
                        if (option == 1) {
                            int numBooks;
                            cout << "How many books do you want to borrow? (Max 5): ";
                            cin >> numBooks;
                            if (member->borrowBook(library, numBooks)) {
                                cout << "Books borrowed successfully!" << endl;
                            }
                        }
                        else if (option == 2) {
                            member->returnBook();
                        }
                        else if (option == 3) {
                            member->reserveBook(library);
                        }
                        else if (option == 4) {
                            member->viewBorrowedAndReservedBooks();
                        }
                        else if (option == 5) {
                            break;
                        }
                        else {
                            cout << "Invalid choice! Please try again." << endl;
                        }
                    }
                    catch (const LibraryException& e) {
                        cout << "Error: " << e.what() << endl;
                    }
                }
            }
            else if (userType == "Librarian") {
                Librarian* librarian = static_cast<Librarian*>(user);
                while (true) {
                    cout << "\n===== Librarian Menu =====" << endl;
                    cout << "1. Add a Book" << endl;
                    cout << "2. Remove a Book" << endl;
                    cout << "3. Update Book Title" << endl;
                    cout << "4. View All Books" << endl;
                    cout << "5. Exit to Main Menu" << endl;
                    int libChoice;
                    cout << "Enter your choice: ";
                    cin >> libChoice;
                    if (libChoice == 1) {
                        string bookTitle, author;
                        cout << "Enter book title: ";
                        cin.ignore();
                        getline(cin, bookTitle);
                        cout << "Enter author name: ";
                        getline(cin, author);
                        AddBook(bookTitle, author);
                    }
                    else if (libChoice == 2) {
                        string bookTitle;
                        cout << "Enter book title to remove: ";
                        cin.ignore();
                        getline(cin, bookTitle);
                        RemoveBook(bookTitle);
                    }
                    else if (libChoice == 3) {
                        string oldTitle, newTitle;
                        cout << "Enter current book title: ";
                        cin.ignore();
                        getline(cin, oldTitle);
                        cout << "Enter new book title: ";
                        getline(cin, newTitle);
                        UpdateBook(oldTitle, newTitle);
                    }
                    else if (libChoice == 4) {
                        DisplayBooks();
                    }
                    else if (libChoice == 5) {
                        break;
                    }
                    else {
                        cout << "Invalid choice! Try again." << endl;
                    }
                }
            }
            else if (userType == "Administrator") {
                Administrator* admin = static_cast<Administrator*>(user);
                AdminMenu(admin);
            }
        }
        catch (const LibraryException& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const invalid_argument&) {
            cout << "Error: Invalid input. Please enter a number." << endl;
        }
        catch (const out_of_range&) {
            cout << "Error: Input is out of range." << endl;
        }
    }
}

void LibrarySystem::AdminMenu(Administrator* admin) {
    while (true) {
        cout << "\n===== Administrator Menu =====" << endl;
        cout << "1. Add Member" << endl;
        cout << "2. Remove Member" << endl;
        cout << "3. Add Librarian" << endl;
        cout << "4. Remove Librarian" << endl;
        cout << "5. View All Users" << endl;
        cout << "6. Exit to Main Menu" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            RegisterMember();
        }
        else if (choice == 2) {
            string memberID;
            cout << "Enter Member ID to remove: ";
            cin >> memberID;
            RemoveMember(memberID);
        }
        else if (choice == 3) {
            RegisterLibrarian();
        }
        else if (choice == 4) {
            string librarianID;
            cout << "Enter Librarian ID to remove: ";
            cin >> librarianID;
            RemoveLibrarian(librarianID);
        }
        else if (choice == 5) {
            DisplayUsers();
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Invalid choice! Try again." << endl;
        }
    }
}