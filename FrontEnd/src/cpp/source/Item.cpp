#include "../header/Item.h"

/**
 * Description: Constructs an item with its information.
 * Input: the item name, the seller's username, the buyer's username,
 *        the remaining days to auction and the current highest bid on the item
 * Output: N/A 
 */
Item::Item(string itemName, string sellerUsername, string buyerUsername, int remainingDays, float currentBid){
    this->itemName = itemName;
    this->sellerUsername = sellerUsername;
    this->buyerUsername = buyerUsername;
    this->remainingDays = remainingDays;
    this->currentBid = currentBid;
}


/**
 * Description: Return the item name
 * Input: N/A
 * Output: itemName of type std::string
 */
string Item::get_itemName() {
    return this->itemName;
}

/**
 * Description: Return the seller name
 * Input: N/A
 * Output: sellerUsername of type std::string
 */
string Item::get_sellerName() {
    return this->sellerUsername;
}

/**
 * Description: Return the buyer name
 * Input: N/A
 * Output: sellerUsername of type std::string
 */
string Item::get_buyerName() {
    return this->buyerUsername;
}

/**
 * Description: Return the remaining days
 * Input: N/A
 * Output: remainingDays of type int
 */
int Item::get_remainingDays() {
    return this->remainingDays;
}

/**
 * Description: Return the current bid
 * Input: N/A
 * Output: currentBid of type float
 */
float Item::get_currentBid() {
    return this->currentBid;
}

/**
 * Description: overloaded equals to operator, will return true if both the 
 *  item name and the seller username are the same
 * Inputs: 2 Item instatnces to compare
 * Outputs: boolean value 
 */
bool operator== (const Item &i1, const Item &i2) {
    return (i1.itemName == i2.itemName) &&
            (i1.sellerUsername == i2.sellerUsername);
}

/**
 * Description: overloaded not equal to operator, will return true if either 
 *  the item name or the seller username are not the same
 * Inputs: 2 Item instatnces to compare
 * Outputs: boolean value 
 */
bool operator!= (const Item &i1, const Item &i2) {
    return (i1.itemName != i2.itemName) ||
            (i1.sellerUsername != i2.sellerUsername);
}