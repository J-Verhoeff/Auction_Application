#ifndef __Delete_h__
#define __Delete_h__

#include <vector>

#include "Transaction.h"

// Description: This class deletes a user from the auction app. This 
//  transaction is only available to admin users. Inherits from the 
//  Transaction class
// Inputs: The current user, of type User
// Ouptuts: N/A
class Delete : public Transaction{

private:
    User *userCalling;
    vector<User> currUsers;
    
public:
    Delete(User &user, User &userCalling, vector<User> currUsers);
    string deleteUser();
    vector<User> setUsers();
};

#endif