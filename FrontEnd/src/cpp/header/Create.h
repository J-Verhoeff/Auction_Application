#ifndef __Create_h__
#define __Create_h__

#include "Transaction.h"
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>

// Description: This class creates a new user for the auction app. This 
//  transaction is only available to admin users. Inherits from the Transaction
//  class
// Inputs: The current user, of type User
// Ouptuts: N/A
class Create : public Transaction{
    private:
        // const values to check for invalid entries
        const int MAX_USERNAME_SIZE = 15;
        const double MAX_CREDIT = 999999.99;
        const string USER_TYPES[4] = {"admin", "full-standard", "buy-standard", "sell-standard"}; 
        const string TRANSACTIONS[8] = {"login", "logout", "create", "delete",
                                        "advertise", "bid", "refund", 
                                        "addCredit"};        
        
        vector<User> currentUsers;

    public:
        Create(User &user, vector<User> currentUsers);
        string createNewUser();
};

#endif