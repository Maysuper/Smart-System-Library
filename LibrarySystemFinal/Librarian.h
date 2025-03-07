#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "User.h"

using namespace std;

class Librarian : public User {
public:
    Librarian(string userName, string userId, string password)
        : User(userName, userId, password) {
    }

    void displayInformation() override;
};

#endif // LIBRARIAN_H