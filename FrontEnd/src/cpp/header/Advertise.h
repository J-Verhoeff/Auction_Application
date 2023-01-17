#ifndef __Advertise_h__
#define __Advertise_h__

#include <vector>

#include "Transaction.h"
#include "Item.h"

/**
 * Description: This class handles the advertise transaction for the system.
 *  It takes in the current user and then creates a new item based on command 
 *  line inputs from the user
 * Input: current user, of type User
 * Ouput: N/A
 */
class Advertise : public Transaction{
    private:
        const float MAX_PRICE = 999.99;
        const int MAX_DAYS_TO_AUCTION = 100;
        const int MAX_NAME_LENGTH = 19;

        vector<Item> availableItems;

    public:
        Advertise(User &user, vector<Item> availableItems);
        string advertiseNewItem();
};

#endif