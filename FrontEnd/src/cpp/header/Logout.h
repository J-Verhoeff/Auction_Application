#ifndef __Logout_h__
#define __Logout_h__

#include <vector>
#include <ctime>
#include <direct.h>

#include "Transaction.h"

using namespace std;

/**
 * Description: Logout transaction, logs user out of session and writes all 
 * the transactions to the daily transaction file.
 * Inputs: The current user
 * Output: The daily transaction text file for that session
 */
class Logout : public Transaction{
    private:
        // constant value for directory to daily transactions
        const string DAILY_TRANSACTIONS_DIR = 
            "resources/dailyTransactions";

    public:
        Logout(User &user); // constructor, passes current user
        void endSession(vector<string> transactions); // ends session
        
};

#endif