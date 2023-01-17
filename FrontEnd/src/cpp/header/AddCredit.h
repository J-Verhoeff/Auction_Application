#ifndef __AddCredit_h__
#define __AddCredit_h__

#include <vector>

#include "Transaction.h"

/**
 * Description: This class handles the addCredit transaction for the system.
 *  It takes in the current user, then taking the desired user as input adds 
 *  credit to a desired limit up to a set limit
 * Inputs: current user, of type User
 * Outputs: N/A
 */
class AddCredit : public Transaction{
    private:
        const float MAX_CREDIT = 1000;

        vector<User> currUsers;

        float validateCredit(string credit);
    public:
        AddCredit(User &user, vector<User> currUsers);
        string addUserCredit();
        float setCredit();
        vector<User> setUsers();        
};

#endif