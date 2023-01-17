#ifndef __User_h__
#define __User_h__

#include <string>

using namespace std;

/**
 * Description: A user has a user type, a username and a credit amount.
 * An object of User is initialized to a no type user at the start
 * of the program and then changes its properties when the user logs in.
 * Input: N/A
 * Output: N/A
 */
class User{

private:
    string username;
    string userType; // NN: notype, AA: admin, FS: full-standard, BS: buy-standard, SS: sell-standard
    float credit;
    float creditAddedInSession;

public:
    User();
    User(string username, string userType, float credit);
    string getUsername();
    string getUserType();
    float getCredit();
    float getCreditAddedInSession();
    void setUsername(string username);
    void setUserType(string userType);
    void setCredit(float credit);
    void setCreditAddedInSession(float creditAddedInSession);
};

#endif