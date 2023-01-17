#ifndef __Bid_h__
#define __Bid_h__

#include <vector>

#include "Transaction.h"
#include "Item.h"

/**
 * Description: This class handles the Bid transaction for the auction system.
 *  It is a semi-privledged transaction that interacts with the user on the 
 *  command line to post a new bid on an existing item in the available
 *  items list.
 * Input: the current user, of type User
 * Ouptut: N/A
 */
class Bid : public Transaction{
    private:
        const float MAX_BID_AMOUNT = 999.99;
        vector<Item> availableItems; 
    public:
        Bid(User &user, vector<Item> availableItems);
        string postNewBid();
        vector<Item> setItems();
};

#endif