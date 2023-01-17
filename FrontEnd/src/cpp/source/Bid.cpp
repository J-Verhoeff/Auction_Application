#include "../header/Bid.h"

/**
 * Description: This is the constructor for the Bid class, inherits from the
 *  Transaction parent class.
 * Input: the current user, of type User
 * Output: N/A
 */
Bid::Bid(User &user, vector<Item> availableItems) : Transaction(user) {
    this->transcode = 4;
    this->availableItems = availableItems;
};

/**
 * Description: This method posts a new bid to an existing item. This method 
 *  will interact with the user via the command line to find an existing item and
 *  post a new bid on it. 
 * Input: N/A
 * Output: preformated string that represents the transaction, of type 
 *  std::string 
 */
string Bid::postNewBid() {
    // comunicate with the user to get the item name and seller name
    string itemName, sellerName;
    cout << "Item name: ";
    cin >> itemName;
    cout << "Seller's username: ";
    cin >> sellerName;

    // check if bidding on own item
    if(sellerName == this->user->getUsername()){
        cout << "Cannot bid on own item!" << endl;
        return "error";
    }

    // check if the item exists
    bool itemExists = false;
    Item* itemToBid;
    for(Item current : availableItems) {
        if(current.get_itemName() == itemName && current.get_sellerName() == sellerName) {
            itemExists = true;
            itemToBid = &current;
            // check if current highest bidder
            if(itemToBid->get_buyerName() == sellerName) {
                cout << "You are the current highest bidder!" << endl;
                return "error";
            }
        }
    }
    if(!itemExists) {
        cout << "No match found for item and user!" << endl;
        return "error";
    }

    // if item exists display the curent bid
    cout << "Current highest bid: " << itemToBid->get_currentBid() << endl;
    
    // ask for new bid from user
    string newBid;
    cout << "New bid amount: ";
    cin >> newBid;

    // check if a valid entry
    int numDots = 0;
    int decimalCount = 0;
    for(int i = 0; i < newBid.length(); i++){
        if(newBid[i] == '.'){
            numDots++;
            if(numDots > 1) {
                cout << "New bid amount must be a number between 0 and 999,999.99!" 
                    << endl;
                return "error";
            }
        }
        else if(numDots == 1){
            decimalCount++;
            if(decimalCount > 2) {
                cout << "Credit amount can only have 2 decimal places!" << endl;
                return "error";
            }
        }
        if(!isdigit(newBid[i]) && newBid[i] != '.'){
            cout << "Credit amount must be a number between 0 and 999,999.99!" 
                    << endl;
            return "error";
        }
    }

    // check if the value is in the range
    float newBidValue = stof(newBid);
    if(newBidValue < (itemToBid->get_currentBid() + 
      (itemToBid->get_currentBid() * 0.05))
      || newBidValue > MAX_BID_AMOUNT) {
        cout << "Credit amount must be a number between 0 and 999,999.99!" << 
            endl;
        return "error";
    }

    // check if its greater than the amount of credit that the user has
    if(newBidValue > this->user->getCredit()){
        cout << "Account has insufficient funds to make this bid!" << endl;
        return "error";
    }

    // Item has been successfully bided
    cout << "Item successfully bidded!" << endl;
    return recordTransaction(sellerName, *itemToBid);
};

/**
 * Description: Method that returns the Items vector to set new item bids
 *  on the main menu
 * Inputs: N/A
 * Outputs: Items vector, of type std::vector<Item>
 */
vector<Item> Bid::setItems() {
    return this->availableItems;
}