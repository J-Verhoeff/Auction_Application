#ifndef __Refund_h__
#define __Refund_h__

#include <vector>

#include "Transaction.h"

/**
 * Description: This class handles the refund transaction for the auction
 *  system. It inherits from the transaction class. It handles an admin 
 *  user providing a refund between a buyer and a seller via command line
 *  input
 * Input: the current user, of type User
 * Output: N/A
 */
class Refund : public Transaction{
    private:
        const float MAX_REFUND = 999999.99;

        vector<User> currUsers;

        User loadUser(string username);
    public:
        Refund(User &user, vector<User> currUsers);
        string performRefund();
        vector<User> setUsers();
};

#endif