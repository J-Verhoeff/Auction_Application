#include "../header/AddCredit.h"

/**
 * Description: Constructor for the AddCredit class, inherits from 
 *  the transaction parent class and sets the transcode to 06
 * Input: the current user, of type User
 * Output: N/A
 */
AddCredit::AddCredit(User &user, vector<User> currUsers) : Transaction(user){
    this->currUsers = currUsers;
    this->transcode = 6;
};

/**
 * Description: This method interacts with the current user on the command 
 *  line to add credit to the desired user. Will check that the user is valid
 *  and has not exceeded the daily limit.
 * Input: credit amount added in session for the user in int format
 * Output: preformated string to represent transaction, of type std::string
 */
string AddCredit::addUserCredit() {
    string creditString;
    cout << "Amount of credit: ";
    cin >> creditString;

    //validate credit
    float credit = validateCredit(creditString);

    if (credit == -1){
        return "error";
    }

    // Add valid credit for standard user
    // (admin user has not setup a username yet for the user to add credit to)
    if (this->user->getUsername() != ""){
        this->user->setCredit(this->user->getCredit() + credit);
    }
    // Admin only
    else {
        string username;
        cout << "Username: ";
        cin >> username;

        // validate the user exists
        bool validUser = false;
        int userIndex;
        for(int u = 0; u < this->currUsers.size(); u++) {
            if(this->currUsers[u].getUsername() == username){
                userIndex = u;
                validUser = true;
            }
        }
        if(!validUser) {
            cout << "User not found!" << endl;
            return "error";
        }

        this->currUsers[userIndex].setCredit(this->currUsers[userIndex].getCredit() + credit);
        this->user->setUsername(this->currUsers[userIndex].getUsername());
        this->user->setUserType(this->currUsers[userIndex].getUserType());
        this->user->setCredit(this->currUsers[userIndex].getCredit());
        this->user->setCreditAddedInSession(this->currUsers[userIndex]
                                            .getCreditAddedInSession());
        this->currUsers[userIndex].setCreditAddedInSession(currUsers[userIndex]
                                    .getCreditAddedInSession() + credit);
    }

    this->user->setCreditAddedInSession(this->user->getCreditAddedInSession() + credit);
    cout << "Successfully added credit!" << endl;
    cout << "Current credit amount: " << this->user->getCredit() 
        << " for " << this->user->getUsername() << endl;

    return recordTransaction();
};

/**
 * Description: Validates that the user inputed credit amount is a valid amount.
 * Input: amount of credit in string format, credit amount added in session for 
 *  the user in int format
 * Output: the credit amount if the credit is valid and -1 if the credit is invalid
 */
float AddCredit::validateCredit(string credit){

    // check if numerical input
    int numDots = 0;
    int decimalCount = 0;
    for(int i = 0; i < credit.length(); i++){
        if(credit[i] == '.'){
            numDots++;
            if(numDots > 1) {
                cout << "Credit amount must be a number between 0.01 and 1000.00!"
                    << endl;
                return -1;
            }
        }
        else if(numDots == 1){
            decimalCount++;
            if(decimalCount > 2) {
                cout << "Credit amount can only have 2 decimal places!" << endl;
                return -1;
            }
        }
        if(!isdigit(credit[i]) && credit[i] != '.'){
            cout << "Credit amount must be a number between 0.01 and 1000.00!"
                    << endl;
            return -1;
        }
    }

    // check if in range 0.01 to 1000.00
    float newCreditAmount = stof(credit);
    if(newCreditAmount > MAX_CREDIT || newCreditAmount < 0.01f) {
         cout << "Credit amount must be a number between 0.01 and 1000.00!" 
            << endl;
        return -1;
    }

    if (newCreditAmount + this->user->getCreditAddedInSession() > 1000){
        cout << "A maximum of 1000$ can be added to an account in a session!"
            << endl;
        return -1;
    }

    if (newCreditAmount + this->user->getCredit() >= 1000000){
        cout << "User cannot exceed the maximum amount of credit of 999,999.99!"
            << endl;
        return -1;
    }

    return newCreditAmount;
}

/**
 * Description: Sets the credit for the mainmenu
 * Inputs: N/A
 * Outputs: The credit amount, of type float
 */
float AddCredit::setCredit() {
    return user->getCredit();
}

/**
 * Description: Sets the user vector for the mainmenu
 * Inputs: N/A
 * Outputs: Updated user vector, of type std::vector<User>
 */
vector<User> AddCredit::setUsers() {
    return this->currUsers;
}