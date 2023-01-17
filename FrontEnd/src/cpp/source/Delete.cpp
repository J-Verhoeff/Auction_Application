#include "../header/Delete.h"

// Description: Constructor for the Delete class. Inherits from the Transaction
//  parent class constructor
// Inputs: the current user, of type User
// Outputs: N/A
Delete::Delete(User &user, User &userCalling, vector<User> currUsers) : Transaction(user) {
    this->transcode = 2;
    this->userCalling = &userCalling;
    this->currUsers = currUsers;
}

// Description: The method will ask for the username and check if its a valid username.
// Input: N/A
// Output: Formated transaction string, of type std::string, error if not valid
string Delete::deleteUser(){

    // Require username
    string username;
    cout << "Username: ";
    cin >> username;

    if (username == this->userCalling->getUsername()){
        cout << "Cannot delete current user!" << endl;
        return "error";
    }
    else{
        // find the user to be deleted
        bool isValidUser = false;
        int userIndex;
        for(int u = 0; u < this->currUsers.size(); u++) {
            if(username == this->currUsers[u].getUsername()) {
                isValidUser = true;
                userIndex = u;
            }
        }
        if(!isValidUser){
            cout << "User not found!" << endl;
            return "error";
        }
        cout << "User successfully deleted!" << endl;
        this->user->setUsername(username);
        this->user->setUserType(this->currUsers[userIndex].getUsername());
        this->user->setCredit(this->currUsers[userIndex].getCredit());
        this->currUsers.erase(this->currUsers.begin() + (userIndex - 1));

        return recordTransaction();
    }
}

/**
 * Description: Sets the updated users vector in the mainmenu
 * Inputs: N/A
 * Outputs: the users vector, of type std::vector<User>
 */
vector<User> Delete::setUsers() {
    return this->currUsers;
}
