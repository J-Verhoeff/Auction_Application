#ifndef __Login_h__
#define __Login_h__

#include <iostream>
#include <fstream>
#include <iomanip>

#include "User.h"

/**
 * Description: Allows a 'no type' user to login to an existing account.
 * Input: current user (not logged in)
 * Output: N/A 
 */
class Login{


private:
    User *user;
    const string USERS_FILEPATH = 
        "resources/currentUserAccounts.txt";

    void requestInfo();
    void validateUser(string username);
    string findUser(string username);
    void welcomeUser();

public:
    Login(User &user);

};

#endif