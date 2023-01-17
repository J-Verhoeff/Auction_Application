#include "../header/User.h"

/**
 * Description: Constructs a blank user with no type.
 * This blank user has no username or credit amount.
 * Input: N/A
 * Output: N/A
 */
User::User(){
    this->userType = "NN";
    this->creditAddedInSession = 0;
}

/**
 * Description: Constructs a user with its username, user type
 * and credit amount given in parameters.
 * Input: the username, userType and credit amount of the user
 * Output: N/A
 */
User::User(string username, string userType, float credit){
    this->username = username;
    this->userType = userType;
    this->credit = credit;
    this->creditAddedInSession = 0;
}

/**
 * Description: Gets the user type of the user.
 * NN: notype, AA: admin, FS: full-standard, BS: buy-standard, SS: sell-standard
 * Input: N/A
 * Output: String format of usertype
 */
string User::getUserType(){
    return userType;
}

/**
 * Description: Gets the username of the user.
 * Input: N/A
 * Output: String format of username
 */
string User::getUsername(){
    return username;
}

/**
 * Description: Gets the credit amount of the user.
 * Input: N/A
 * Output: Float format of credit amount
 */
float User::getCredit(){
    return credit;
}

/**
 * Description: Gets the credit amount of the user.
 * Input: N/A
 * Output: Float format of credit amount
 */
float User::getCreditAddedInSession(){
    return creditAddedInSession;
}

/**
 * Description: Sets the user type of the user.
 * Input: String format of user type to set
 * Output: N/A
 */
void User::setUserType(string userType){
    this->userType = userType;
}

/**
 * Description: Sets the username of the user.
 * Input: String format of username to set
 * Output: N/A
 */
void User::setUsername(string username){
    this->username = username;
}

/**
 * Description: Sets the credit amount of the user.
 * Input: Float format of credit amount to set
 * Output: N/A
 */
void User::setCredit(float credit){
    this->credit = credit;
}

/**
 * Description: Sets the credit added in session amount of the user.
 * Input: Float format of credit amount to set
 * Output: N/A
 */
void User::setCreditAddedInSession(float creditAddedInSession){
    this->creditAddedInSession = creditAddedInSession;
}