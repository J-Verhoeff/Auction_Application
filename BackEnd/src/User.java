package src;

/**
 * Description: This class stores each of the users found in the current
 *  User accounts file in an object
 * Inputs: username, user type, and avalble credit
 * Outputs: N/A
 */
public class User {

    // private instance variables
    private String username;
    private String userType;
    private double availableCredit;

    /**
     * Description: Default constructor for User class
     * Inputs: N/A
     * Outputs: N/A
     */
    public User() {
        this.username = "";
        this.userType = "";
        this.availableCredit = 0.0;
    }

    /**
     * Description: Constructor for the User class
     * Inputs: username, user type, and the useres available credit
     * Outputs: N/A
     */
    public User(String username, String userType, double availableCredit) {
        this.username = username;
        this.userType = userType;
        this.availableCredit = availableCredit;
    }

    /**
     * Description: Constructor to be used with the trasnaction string
     * Input: The string input from the Daily Transactions file
     * Output: N/A
     */
    public User(String line){
         this.username = line.substring(0,15);//remove trailing strings here
         this.userType = line.substring(16,19);
         this.availableCredit = Double.parseDouble( line.substring (19,28) );
    }

    /**
     * @param availableCredit the availableCredit to set
     */
    public void setAvailableCredit(double availableCredit) {
        this.availableCredit = availableCredit;
    }

    /**
     * @param userType the userType to set
     */
    public void setUserType(String userType) {
        this.userType = userType;
    }

    /**
     * @param username the username to set
     */
    public void setUsername(String username) {
        this.username = username;
    }

    /**
     * @return the availableCredit
     */
    public double getAvailableCredit() {
        return availableCredit;
    }

    /**
     * @return the userType
     */
    public String getUserType() {
        return userType;
    }

    /**
     * @return the username
     */
    public String getUsername() {
        return username;
    }
}
