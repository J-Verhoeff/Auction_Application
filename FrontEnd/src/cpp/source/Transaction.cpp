#include <iomanip>
#include "../header/Transaction.h"

// Description: Parent constructor for the transaction class.
// Input: the current user, of type User
// Output: N/A
Transaction::Transaction(User &user) {
    this->user = &user;
};

// Description: method to convert the float credit amount into the desired 
//  string format for the Daily Transaction File. For users the format is
//  999999.99 and for items it is 999.99
// Input: credit amount from User class, of type float
// Output: the credit in the string format, of type std::string
string Transaction::formatCredit(float credit, string type){
    double desiredFormat;
    if(type == "user") {
        desiredFormat = 1000000.00 + credit;
        return to_string(desiredFormat).substr(1,9);
    }
    else if (type == "item") {
        desiredFormat = 1000.00 + credit;
        return to_string(desiredFormat).substr(1,6);
    } 
    else {
        cout << "Incorrect string type" << endl;
    }
    return "";
};

// Description: Method to create string format to record the transaction.
//  Used for create, delete, addCredit and logout transactions.
// Input: N/A
// Output: Formated string to write to the daily transaction file
string Transaction::recordTransaction(){
    string toWrite = "0"; // initial string
    
    // add the transcode to the string
    toWrite += to_string(this->transcode) + " ";

    //add the username to the string
    string username = this->user->getUsername();
    // loop through username and add to string or space if empty
    for(int i = 0; i < 15; i++) {
        if(i < username.length()) {
            toWrite += username[i];
        } else {
            toWrite += " ";
        }
    }

    // add userType to the string
    toWrite += " " + this->user->getUserType() + " ";

    // add credit to the string
    toWrite += formatCredit(this->user->getCredit(), "user");

    return toWrite;
};

// Description: Method to create string format to record the transaction.
//  Used for Refund transaction.
// Input: the Seller user
// Output: Formated string to write to the daily transaction file, of type 
//  std::string
string Transaction::recordTransaction(string sellerUsername, 
                                      string buyerUsername, 
                                      float refundCredit) {
    string toWrite = "0";

    // add transcode to the string
    toWrite += to_string(this->transcode) + " ";

    // Add the buyer name to the string
    // loop through username and add to string or space if empty
    for(int i = 0; i < 15; i++) {
        if(i < buyerUsername.length()) {
            toWrite += buyerUsername[i];
        } else {
            toWrite += " ";
        }
    }
    toWrite += " ";

    // Add the seller name to the string
    // loop through username and add to string or space if empty
    for(int i = 0; i < 15; i++) {
        if(i < sellerUsername.length()) {
            toWrite += sellerUsername[i];
        } else {
            toWrite += " ";
        }
    }
    toWrite += " ";

    // add the refund credit to the string
    toWrite += formatCredit(refundCredit, "user");

    return toWrite;
};

// Description: Method to create string format to record the transaction.
//  Used for Advertise transaction.
// Input: the Item that is being advertised
// Output: Formated string to write to the daily transaction file, of type 
//  std::string
string Transaction::recordTransaction(Item &item) {
    string toWrite = "0"; // initial string

    // add transcode to the string
    toWrite += to_string(this->transcode) + " ";

    // add item name to the transaction
    string itemName =  item.get_itemName();
    // loop through item name and add blanks if less then max length
    for(int i = 0; i < 19; i++) {
        if(i < itemName.length()) {
            toWrite += itemName[i];
        } else {
            toWrite += " ";
        }
    }
    toWrite += " ";

    // Add username to the tranasaction
    string username = this->user->getUsername();
    // loop through username and add to string or space if empty
    for(int i = 0; i < 15; i++) {
        if(i < username.length()) {
            toWrite += username[i];
        } else {
            toWrite += " ";
        }
    }
    toWrite += " ";

    // number of days to auction
    int numDays = 1000;
    numDays += item.get_remainingDays();
    toWrite += to_string(numDays).substr(1,3) + " ";

    // add the item amount to the transaction
    toWrite += formatCredit(item.get_currentBid(), "item");
    
    return toWrite;
};

// Description: Method to create string format to record the transaction.
//  Used for bid transaction.
// Input: The seller of the item and the Item that is being bid on
// Output: Formated string to write to the daily transaction file, of type 
//  std::string
string Transaction::recordTransaction(string sellerUsername, Item &item) {
    string toWrite = "0";

    // add the transaction code to the transaction
    toWrite += to_string(this->transcode) + " ";

    // add the item name to the transaction
    string itemName = item.get_itemName();
     // loop through item name and add blanks if less then max length
    for(int i = 0; i < 19; i++) {
        if(i < itemName.length()) {
            toWrite += itemName[i];
        } else {
            toWrite += " ";
        }
    }
    toWrite += " ";

    // add the sellers username to the transaction
    for(int i = 0; i < 15; i++) {
        if(i < sellerUsername.length()) {
            toWrite += sellerUsername[i];
        } else {
            toWrite += " ";
        }
    }
    toWrite += " ";

    // add the buyers username to the transaction
    string buyersUsername = this->user->getUsername();
    for(int i = 0; i < 15; i++) {
        if(i < buyersUsername.length()) {
            toWrite += buyersUsername[i];
        } else {
            toWrite += " ";
        }
    }
    toWrite += " ";

    // add the new bid the the transaction
    toWrite += formatCredit(item.get_currentBid(), "item");
    
    return toWrite;
};