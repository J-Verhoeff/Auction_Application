#include "../header/Refund.h"

/**
 * Description: This is the constructor for the Refund class, it inherits from
 *  the Transaction class.
 * Input: The current user, of type User
 * Output: N/A
 */
Refund::Refund(User &user, vector<User> currUsers) : Transaction(user){
    this->transcode = 5;
    this->currUsers = currUsers;
};

/**
 * Description: Loads the buyer or seller from a given username
 * Inputs: username, of type std::string
 * Outputs: a new User, of type User
 */
User Refund::loadUser(string username) {
    // load the users file
    User newUser;

    // loop through vector and find user
    for(int u = 0; u < this->currUsers.size(); u++) {
        if(username == this->currUsers[u].getUsername()) {
            newUser = this->currUsers[u];
            break;
        }
    }
    return newUser;
}

/**
 * Description: This method creates a refund transaction between a buyer and 
 *  a seller. It will subtract the credit from the seller and give it to the 
 *  buyer. Returns a preformatted string that represents the transaction to be 
 *  posted into the Daily Transaction file.
 * Input: N/A
 * Output: The preformatted string that represents the tranaction, of type
 *  std::string 
 */
string Refund::performRefund() {
    // get the buyer username from the command line
    string buyersUsername;
    cout << "Buyer's username: ";
    cin >> buyersUsername;

    // load buyer and check if buyer exists
    User buyer = loadUser(buyersUsername);
    if(buyer.getUserType() == "NN") {
        cout << "Buyer not a user!" << endl;
        return "error";
    }

    // get the seller's username from the command line
    string sellersUsername;
    cout << "Seller's username: ";
    cin >> sellersUsername;

    // load the seller and check if the seller exists
    User seller = loadUser(sellersUsername);
    if(seller.getUserType() == "NN") {
        cout << "Seller not a user!" << endl;
        return "error";
    }

    // check to ensure buyer and seller are not the same user
    if(seller.getUsername() == buyer.getUsername()) {
        cout << "Buyer and seller cannot be the same user!" << endl;
        return "error";
    }

    // ask the user for the amount of credit to transfer
    string refundCredit;
    cout << "Amount of credit: ";
    cin >> refundCredit;

    // check if a valid amount
    float creditValue = stof(refundCredit);
    if(creditValue < 0 || creditValue > MAX_REFUND) {
        cout << "Amount of credit must be between 0 and 999,999!" << endl;
        return "error";
    }

    // check if seller has enough credit
    if(creditValue > seller.getCredit()) {
        cout << "Insufficient amount of credit in Seller's account!" << endl;
        return "error";
    }

    // User has made a successful refund
    cout << "Successfully refunded buyer!" << endl;
    // update the vector with the new credit values
    int buyerIndex, sellerIndex;
    for(int u = 0; u < this->currUsers.size(); u++) {
        if(buyer.getUsername() == this->currUsers[u].getUsername()) {
            buyerIndex = u;
        }
        else if(seller.getUsername() == this->currUsers[u].getUsername()) {
            sellerIndex = u;
        }
    }
    this->currUsers[sellerIndex].setCredit(this->currUsers[sellerIndex].
                                            getCredit()-creditValue);
    this->currUsers[buyerIndex].setCredit(this->currUsers[buyerIndex].
                                            getCredit()+creditValue);
    return recordTransaction(seller.getUsername(), 
                             buyer.getUsername(),
                             creditValue);
};

/**
 * Description: Function to update the user vector in the mainmenu
 * Inputs: N/A
 * Outputs: the users vector, of type std::vector<User>
 */
vector<User> Refund::setUsers() {
    return this->currUsers;
}