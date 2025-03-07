#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include "LibraryException.h"

using namespace std;

class User {
public:
    string userName;
    string userId;
    string password;

    User(string userName, string userId, string password)
        : userName(userName), userId(userId), password(password) {
    }

    virtual void displayInformation();
};

#endif // USER_H