#include "../header/Create.h"

// Description: Constructor for the Create class. Inherits from the Transaction
//  parent class constructor
// Inputs: the new user, of type User
// Outputs: N/A
Create::Create(User &user,  vector<User> currentUsers) : Transaction(user) {
    this->transcode = 1;
    this->currentUsers = currentUsers;
}

// Description: The method will ask for the username, followed by the type of user, 
//  and the initial credit amount the user will have. The method returns the 
//  formatted string representing the transaction
// Input: N/A
// Output: Formated transaction string, of type std::string
string Create::createNewUser(){
    string newUsername;
    cout << "New username: ";
    cin >> newUsername;

    // check if already existing username
    bool usernameExists = false;
    for(int u = 0; u < this->currentUsers.size(); u++) {
        if(currentUsers[u].getUsername() == newUsername) {
            usernameExists = true;
        }
    }
    if(usernameExists){
        cout << "New username cannot be an already existing username!" << endl;
        return "error";
    }

    // check if a transaction name
    bool isTranscode = any_of(begin(this->TRANSACTIONS), end(this->TRANSACTIONS), 
                        [&](string i) {return i == newUsername;});
    if(isTranscode){
        cout << "New username cannot be a transaction code!" << endl;
        return "error";
    }

    // check if the entered username is over 15 characters
    if(newUsername.length() > this->MAX_USERNAME_SIZE) {
        cout << "New username cannot be over 15 characters!" << endl;
        return "error";
    }

    // check if the entered username is blank
    if(newUsername.length() <= 0){
        cout << "New username cannot be blank!" << endl;
        return "error";
    }

    // Ask for new user type
    string newUserType;
    cout << "Type of user (admin, full-standard, buy-standard, sell-standard): ";
    cin >> newUserType;

    // check if user type is valid
    bool isUserType = any_of(begin(this->USER_TYPES), end(this->USER_TYPES), 
                        [&](string i) {return i == newUserType;});
    if(!isUserType){
        cout << "Type of user cannot be other than the options listed!" << endl;
        return "error";
    }

    // convert type of user to code
    if (newUserType == "admin"){
        newUserType = "AA";
    }
    if (newUserType == "full-standard"){
        newUserType = "FS";
    }
    if (newUserType == "buy-standard"){
        newUserType = "BS";
    }
    if (newUserType == "sell-standard"){
        newUserType = "SS";
    }

    // ask for intital credit amount
    string initialCredit;
    cout << "Credit amount: ";
    cin >> initialCredit;

    // check if numerical input
    int numDots = 0;
    int decimalCount = 0;
    for(int i = 0; i < initialCredit.length(); i++){
        if(initialCredit[i] == '.'){
            numDots++;
            if(numDots > 1) {
                cout << "Credit amount must be a number between 0 and 999,999.99!" 
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
        if(!isdigit(initialCredit[i]) && initialCredit[i] != '.'){
            cout << "Credit amount must be a number between 0 and 999,999.99!" 
                    << endl;
            return "error";
        }
    }

    // check if in range 0 to 999999.99
    double newCreditAmount = stof(initialCredit);
    if(newCreditAmount > MAX_CREDIT || newCreditAmount < 0) {
         cout << "Credit amount must be a number between 0 and 999,999.99!" 
            << endl;
        return "error";
    }

    // valid input
    cout << "New user successfully created!" << endl;

    // set values to the new user
    user->setUsername(newUsername);
    user->setUserType(newUserType);
    user->setCredit(newCreditAmount);

    // return the string to record the transaction
    return recordTransaction();
}