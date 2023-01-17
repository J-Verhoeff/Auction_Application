#ifndef __MainMenu_h__
#define __MainMenu_h__

#include <map>
#include <vector>
#include <fstream>

#include "User.h"
#include "Login.h"
#include "Item.h"
#include "Logout.h"
#include "Create.h"
#include "Delete.h"
#include "Advertise.h"
#include "Bid.h"
#include "Refund.h"
#include "AddCredit.h"

/**
 * Description: This class provides the options that users can choose based on
 * their user type. These options include login, logout, create, delete, advertise
 * bid, refund and addcredit.
 * Input: User type current user
 * Output: N/A
 */
class MainMenu {

private:
    User *user;
    string* options;
    int optionsSZ;
    bool isActive;
    bool isLoggedIn;
    vector<string> dailyTransactions;
    vector<Item> availableItems;
    vector<User> currUserAccounts;
    int *creditAddedInSession;
    string availableItemsFilepath;
    string currUsersFilepath;
    
    void init();
    string* setOptions();
    void exit(); // function to exit application
    void appendTransaction(string trans);
    void loadItems();
    void loadUsers();

public:
    MainMenu(User &user, string availableItemsFilepath, string currUsersFilepath);
    
    void displayOptions();
    void requestOption();

    // get and set functions for isActive
    void set_isActive(bool active);
    bool get_isActive();
};

#endif
