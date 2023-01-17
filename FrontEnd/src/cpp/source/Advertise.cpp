#include "../header/Advertise.h"

/** Description: Constructor for the Advertise transaction, inherits from the 
 *   transaction parent class. 
 * Input: the current user, of type user
 * Output: N/A
 */
Advertise::Advertise(User &user, vector<Item> availableItems) : Transaction(user){
    this->transcode = 3;
    this->availableItems = availableItems;
};

/** 
 * Description: This method interacts with the user via the command line to 
 *  add a new item to be bid on. The method checks to make sure the 
 *  information the user entered was valid then records the new item.
 * Input: N/A
 * Output: preformated string reprresenting the transaction, of type 
 *  std::string
 */
string Advertise::advertiseNewItem(){
    // Ask user for item name
    string newItemName;
    cout << "Item name: ";
    cin >> newItemName;

    // Check if item name is to long
    if(newItemName.length() > MAX_NAME_LENGTH){
        cout << "Item name cannot be over 19 characters!" << endl;
        return "error";
    }

    // Check if the name was left blank
    if(newItemName.length() <= 0) {
        cout << "Item name cannot be blank!" << endl;
        return "error";
    }

    // Ask user for the minimum bid
    string minimumBid;
    cout << "Minimum Bid: ";
    cin >> minimumBid;

    // check if correct numerical entry
    int numDots = 0;
    int decimalCount = 0;
    for(int i = 0; i < minimumBid.length(); i++){
        if(minimumBid[i] == '.'){
            numDots++;
            if(numDots > 1) {
                cout << "Minimum bid amount must be a number between 0 and 999.99!" 
                    << endl;
                return "error";
            }
        }
        else if(numDots == 1){
            decimalCount++;
            if(decimalCount > 2) {
                cout << "Minimum bid amount can only have 2 decimal places!" << endl;
                return "error";
            }
        }
        if(!isdigit(minimumBid[i]) && minimumBid[i] != '.'){
            cout << "Minimum bid amount must be a number between 0 and 999.99!" 
                    << endl;
            return "error";
        }
    }

    // check if in range of 0 to 999.99
    float newMinBid = stof(minimumBid);
    if(newMinBid > MAX_PRICE || newMinBid < 0) {
        cout << "Minimum bid amount must be a number between 0 and 999.99!" 
                    << endl;
        return "error";
    }

    // Ask for number of days to auction
    string daysToAuction;
    cout << "Number of days till auction end: ";
    cin >> daysToAuction;

    // check if numerical entry
    for(int i = 0; i < daysToAuction.length(); i++) {
        if(!isdigit(daysToAuction[i])) {
            cout << "Number of days till auction end must be a whole number between 1 and 100!"
                 << endl;
            return "error";
        }
    }

    // check if the entry is in the range 1 to 100
    int newDaysToAuction = stoi(daysToAuction);
    if(newDaysToAuction > 100 || newDaysToAuction <= 0) {
        cout << "Number of days till auction end must be a whole number between 1 and 100!"
                 << endl;
        return "error";
    }

    Item newItem = Item(newItemName, 
                        user->getUsername(),
                        user->getUsername(), 
                        newDaysToAuction,
                        newMinBid);
    
    // check if item already exists
    for(Item toCompare : this->availableItems) {
        if(toCompare == newItem) {
            cout << "New item must not already exist!" << endl;
            return "error";
        }
    }

    // Item successfully created
    cout << "Advertisement successfully created!" << endl;
    
    return recordTransaction(newItem);
};