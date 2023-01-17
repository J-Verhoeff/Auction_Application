#ifndef __Transaction_h__
#define __Transaction_h__

#include <iostream>
#include <sstream>
#include <fstream>

#include "User.h"
#include "Item.h"

using namespace std;

/**
 * Description: Parent class that defines all transactions except login.
 * Inputs: Current user of type user
 * Output: N/A
 */
class Transaction{
    protected:
        // The User that performed the transaction
        User *user;
        // the transcode for the transaction
        int transcode;

        // method to convert the credit to desired string format
        string formatCredit(float credit, string length);

    public:
        Transaction(User &user); // constructor

        // public methods to create strings to record transactions
        string recordTransaction(); // For create, delete, addcredit, logout
        string recordTransaction(string sellerUsername, string buyerUsername, 
                                float refundCredit); // for refund
        string recordTransaction(Item &item); // for advertise
        string recordTransaction(string sellerUsername, Item &item); // for bid
};

#endif