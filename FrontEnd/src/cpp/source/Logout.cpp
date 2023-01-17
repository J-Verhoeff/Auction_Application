#include "../header/Logout.h"

// Description: Public constructor for logout class, sets the current user.
// Input: The current user
// Output: The daily transaction text file for that session
Logout::Logout(User &user) : Transaction(user){
    this->transcode = 0;
    this->user->setCreditAddedInSession(0);
};

// Description: Ends the current session and records all of the data into a
// Daily Transactions File.
// Input: Vector of all the preformatted transaction strings
// Output: N/A
void Logout::endSession(vector<string> transactions){
    // Set user type to blank user
    this->user->setUserType("NN");

    // Create dailyTransaction folder if not existant
    mkdir("dailyTransactions");

    // Get current time and date
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string fileName = "dailyTransactions/dt_" + to_string(1900 + ltm->tm_year) + 
    to_string(ltm->tm_mon) + to_string(ltm->tm_mday) + "_" +
    to_string(ltm->tm_hour) + to_string(ltm->tm_min) + to_string(ltm->tm_sec) + ".txt";
    
    // Write transactions to file
    ofstream file (fileName);
    if (file.is_open())
    {
        for (auto const& trans : transactions){
            file << trans << endl;
        }
        file.close();
    }
}