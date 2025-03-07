#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"

using namespace std;

class Administrator : public User {
public:
    Administrator(string userName, string userId, string password)
        : User(userName, userId, password) {
    }

    void displayInformation() override;
};

#endif // ADMINISTRATOR_H