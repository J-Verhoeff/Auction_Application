#ifndef __Item_h__
#define __Item_h__

#include <string>

using namespace std;

/**
 * Description: An item has an item name, the seller's username,
 * the buyer's username, the remaining days to auction and the current
 * highest bid on the item.
 * Input: the item name, the seller's username, the buyer's username,
 *        the remaining days to auction and the current highest bid on the item
 * Output: N/A 
 */
class Item{

protected:
    string itemName;
    string sellerUsername;
    string buyerUsername;
    int remainingDays;
    float currentBid;

public:
    Item(string itemName, string sellerUsername, string buyerUsername, 
        int remainingDays, float currentBid);
    
    // overloaded comparison operators
    friend bool operator== (const Item &i1, const Item &i2);
    friend bool operator!= (const Item &i1, const Item &i2);

    // getter functions
    string get_itemName();
    string get_sellerName();
    string get_buyerName();
    int get_remainingDays();
    float get_currentBid();
    friend bool operator== (const Item &i1, const Item &i2);
    friend bool operator!= (const Item &i1, const Item &i2); 
};



#endif