/**
 * Overall program intention:
 * This program called "Auction" is a user based system.
 *  
 * This program will interact with the user on the command line to sell and bid 
 * on items in an auction applicaiton, similar to that of Ebay. The user will 
 * be able to perform transactions pertaining to posting a new item, biding on
 * an existing item, and adding credit to their account.
 * 
 * This program conatains user account with different privileges. An admin user 
 * can create and delete users, and will have special privileges with buying 
 * and selling. Where as buy-standard can only bid, sell-standard can only sell
 * and full-statndard can but and sell. 
 * 
 * All of the items, user data, and session transactions are stored in text 
 * files that will be handled by the back-end of the program 
 * 
 * Authors: Joshua Verhoeff and Peter Nagy
 */
#include <iostream>

#include "../header/MainMenu.h"

// Description: Main function for auction system
// Input: N/A
// Output: N/A
int main(int argc, char **argv){

    // check if correct number of entries
    if(argc < 3) {
        std::cout << "Incorrect number of entries entered" << std::endl;
        std::cout << "Must be in format (auction itemsFile.txt usersFile.txt)"
                  << std::endl;
        return -1;
    }

    User user;
    MainMenu menu(user, argv[1], argv[2]);
    
    while (menu.get_isActive()){
        menu.displayOptions();
        menu.requestOption();
    }

    return 0;
}