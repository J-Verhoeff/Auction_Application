#include "../header/Login.h"

/**
 * Description: Initializes the current user and asks for input.
 * Input: User type current user 
 * Output: N/A 
 */
Login::Login(User &user){
    this->user = &user;
    requestInfo();
}

/**
 * Description: Asks for the user's username and validates it.
 * Input: N/A
 * Output: N/A 
 */
void Login::requestInfo(){
    string username;
    cout << "User: ";
    cin >> username;

    validateUser(username);
}

/**
 * Description: Finds a specific username in the users file.
 * If the username is found output the string representing its user.
 * Else it returns an empty string.
 * Input: the username to search for
 * Output: a string representation of the user if the username is found,
 * otherwise, returns an empty string
 */
string Login::findUser(string username){
    string line;
	ifstream file;
	file.open(USERS_FILEPATH);

	if (file.is_open()) {
		while(getline(file, line)){
            if (line.substr(0, line.find(' ')) == username){
                return line;
            }
        }
        file.close();
    }
    else{
        cout << "File not found" << endl;
    }

    return "";
}

/**
 * Description: Checks if username is a valid user's username.
 * Input: the username to check
 * Output: N/A
 */
void Login::validateUser(string username){

    string userLn = findUser(username);
    
    if (userLn.size() == 0){
        cout << "User not in database!" << endl << endl;
    }
    else{
        user->setUsername(userLn.substr(0, userLn.find(' ')));
        user->setUserType(userLn.substr(16, 2));
        user->setCredit(stof(userLn.substr(19,9)));

        welcomeUser();
    }
}

/**
 * Description: Outputs the information of the user to the console.
 * Input: N/A
 * Output: N/A 
 */
void Login::welcomeUser(){
    cout.precision(2);
    cout << endl << "Welcome " << user->getUsername() << "!" << endl;
    cout << "User Type: " << user->getUserType() << endl;
    cout << "Available Credit: " << fixed << user->getCredit() << "$" << endl;
}

