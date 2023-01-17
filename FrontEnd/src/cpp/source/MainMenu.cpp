#include "../header/MainMenu.h"

/**
 * Description: Sets up the user and the options for him.
 * Input: User type current user
 * Output: N/A
 */
MainMenu::MainMenu(User &user, string availableItemsFilepath, string currUsersFilepath){
    this->availableItemsFilepath = availableItemsFilepath;
    this->currUsersFilepath = currUsersFilepath;
    this->user = &user;
    init();
}

/**
 * Description: Sets the menu active and welcomes the user.
 * Input: N/A
 * Output: N/A
 */
void MainMenu::init(){
    // set bool value to true
    set_isActive(true);

    cout << "\nWelcome to the Auction App!" << endl << 
        "Start entering transactions" << endl <<
        "To exit the application type 'exit'" << endl;

    options = setOptions();
    this->isLoggedIn = false;
    loadUsers();
}

/**
 * Description: If the user is not logged in, then sets the menu inactive.
 * Input: N/A
 * Output: N/A
 */
void MainMenu::exit() {
    if(!this->isLoggedIn){
        cout << "Goodbye!" << endl;
        if(get_isActive()!=false)
            set_isActive(false);
    } else {
        cout << "Cannot exit when logged in!" << endl;
    }
}

/**
 * Description: Displays the options available to the user.
 * Input: N/A
 * Output: N/A
 */
void MainMenu::displayOptions(){

    cout << "\nOptions:" << endl;

    for (int i=0; i<optionsSZ; i++){
        cout << "\t" << options[i] << endl;
    }
}

/**
 * Description: Sets the options available to the user based on its user type.
 * If the user is not logged in (their usertype is 'NN') their only option is 'login'.
 * If the user type is not recognized then it returns an empty array.
 * Input: N/A
 * Output: Returns a string array of options available.
 */
string* MainMenu::setOptions(){

    if (user->getUserType() == "NN"){
        optionsSZ = 1;
        static string arr[1] = {"login"};
        return arr;
    }
    if (user->getUserType() == "AA"){
        optionsSZ = 7;
        static string arr[7] = {"logout", "create", "delete", "advertise", "bid", "refund", "addcredit"};
        return arr;
    }
    if (user->getUserType() == "FS"){
        optionsSZ = 4;
        static string arr[4] = {"logout", "advertise", "bid", "addcredit"};
        return arr;
    }
    if (user->getUserType() == "BS"){
        optionsSZ = 3;
        static string arr[3] = {"logout", "bid", "addcredit"};
        return arr;
    }
    if (user->getUserType() == "SS"){
        optionsSZ = 3;
        static string arr[3] = {"logout", "advertise", "addcredit"};
        return arr;
    }
    
    return {};
}

/**
 * Description: Saves the transaction in the daily transactions array.
 * Input: String format describing transaction.
 * Output: N/A
 */
void MainMenu::appendTransaction(string trans) {
    this->dailyTransactions.push_back(trans);
}

/**
 * Description: Loads the items available to auction into the 'availableItems' vector.
 * Input: N/A
 * Output: N/A
 */
void MainMenu::loadItems() {
    // open the available items file
    ifstream availableItemsFile;
    availableItemsFile.open(this->availableItemsFilepath);
    if(availableItemsFile.is_open()) {
        string line;
        // loop through file and retrieve all items
        while(getline(availableItemsFile, line)) {
            string itemName = line.substr(0, line.find(' '));
            string sellerUsername = line.substr(20, line.find(' '));
            string buyerUsername = line.substr(36, line.find(' '));
            int daysRemaining = stoi(line.substr(52, line.find(' ')));
            float currentBid = stof(line.substr(56));
            // load into items vector
            this->availableItems.push_back(Item(itemName, 
                                                sellerUsername,
                                                buyerUsername,
                                                daysRemaining,
                                                currentBid));
        }
        availableItemsFile.close();
    } else {
        cout << "Could not open Available Items file!" << endl;
        exit();
    }
}

/**
 * Description: Function to load all of the users into a vector
 * Input: N/A
 * Output: N/A
 */
void MainMenu::loadUsers() {
    ifstream usersFile;
    usersFile.open(this->currUsersFilepath);
    if(usersFile.is_open()) {
        string line;
        while(getline(usersFile, line)) {
            string username = line.substr(0, line.find(' '));
            string userType = line.substr(16, line.find(' '));
            float credit = stof(line.substr(19));
            this->currUserAccounts.push_back(User(username, userType, credit));
        }
        usersFile.close();
    } else {
        cout << "Could not open Current User Accounts file!" << endl;
        exit();
    }
}

/**
 * Description: Prompts the user for transaction choice. The user can exit by typing 'exit'.
 * Each transaction is then processed, by creating an object of that transaction.
 * Input: N/A
 * Output: N/A
 */
void MainMenu::requestOption(){

    cout << "Transaction: ";
    string input;
    cin >> input;

    // Check if user wants to exit
    if(input == "exit") {
        exit();
    }
    else {
        // Validate input
        bool found = false;
        for (int i=0; i<optionsSZ; i++){
            if (options[i] == input){
                found = true;
            }
        }

        // Transaction not in options
        if (!found){
            cout << "Transaction not in options!" << endl << endl;
        }
        else if (input == "login"){
            Login login(*user);

            // if user has successfully logged in
            if (user->getUserType() != "NN"){
                this->isLoggedIn = true;
                loadItems();
                options = setOptions();
            }
        }
        else if (input == "logout"){

            Logout logout(*user);

            // Record transaction
            appendTransaction(logout.recordTransaction());

            logout.endSession(dailyTransactions);

            // Erase daily transactions
            this->dailyTransactions.clear();

            // if user has successfully logged out
            if (user->getUserType() == "NN"){
                init();
            }
        }
        else if (input == "create"){
            // create user to be created
            User newUser;
            Create create(newUser, this->currUserAccounts);

            // record transaction
            string newUserString = create.createNewUser();
            if(newUserString != "error"){
                appendTransaction(newUserString);
            }            
        }
        else if (input == "delete"){
            User newUser;
            Delete deleteTrans(newUser, *user, this->currUserAccounts);

            string transString = deleteTrans.deleteUser();
            if (transString != "error"){
                appendTransaction(transString);
                this->currUserAccounts.clear();
                this->currUserAccounts = deleteTrans.setUsers();
            }
        }
        else if (input == "advertise"){
            Advertise advertise(*user, this->availableItems);
            string newAuction = advertise.advertiseNewItem();
            if(newAuction != "error") {
                appendTransaction(newAuction);
            }
        }
        else if (input == "bid"){
            Bid bid(*user, this->availableItems);
            string newBid = bid.postNewBid();
            if(newBid != "error") {
                appendTransaction(newBid);
                this->availableItems.clear();
                this->availableItems = bid.setItems();
            }
        }
        else if (input == "refund"){
            Refund refund(*user, this->currUserAccounts);
            string newRefund = refund.performRefund();
            if(newRefund != "error") {
                appendTransaction(newRefund);
                this->currUserAccounts.clear();
                this->currUserAccounts = refund.setUsers();
            }
        }
        else if (input == "addcredit"){

            string transString;

            if (this->user->getUserType() == "AA"){
                User newUser;
                AddCredit addcredit(newUser, this->currUserAccounts);

                transString = addcredit.addUserCredit();
                this->currUserAccounts.clear();
                this->currUserAccounts = addcredit.setUsers();
            }
            else{
                AddCredit addcredit(*user, this->currUserAccounts);

                transString = addcredit.addUserCredit();
                this->user->setCredit(addcredit.setCredit());
            }
             
            if (transString != "error"){
                appendTransaction(transString);
            }
        }
    }
}

/**
 * Description: Sets the active state of the menu.
 * Input: Boolean state of menu to set
 * Output: N/A
 */
void MainMenu::set_isActive(bool active) {
    this->isActive = active;
}

/**
 * Description: Gets the active state of the menu.
 * Input: N/A
 * Output: Boolean current state of menu
 */
bool MainMenu::get_isActive(){
    return this->isActive;
}


