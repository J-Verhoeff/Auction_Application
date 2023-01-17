package src;

/**
 * Description: Class to store each of the items found in the available items
 *  file and stores them in a object
 * Inputs: item name, seller username, user with highest bid, days remaining,
 *  and the current highest bid
 */
public class Item {
    // private instance variables
    private String name;
    private String sellerUsername;
    private String userWithHighestBid;
    private int daysRemaining;
    private double currentHighestBid;

    /**
     * Description: Default constructor for the Item class
     * Inputs: N/A
     * Outputs: N/A
     */
    public Item(){
        this.name = "";
        this.sellerUsername = "";
        this.userWithHighestBid = "";
        this.daysRemaining = 0;
        this.currentHighestBid = 0.0;
    }

    /**
     * Decription: Constructor for the Item class
     * Inputs: item name, seller username, user with the highest bid, days
     *  remainng at auction, and the current highest bid
     * Outputs: N/A
     */
    public Item(String name,
                String sellerUsername,
                String userWithHighestBid,
                int daysRemaining,
                double currentHighestBid) {

        this.name = name;
        this.sellerUsername = sellerUsername;
        this.userWithHighestBid = userWithHighestBid;
        this.daysRemaining = daysRemaining;
        this.currentHighestBid = currentHighestBid;
    }

    /**
     * Description: Constrctor to be used with transaction string
     * Input: The string taken from the Daily Transactions File
     * Output: N/A
     */
    public Item(String line){
         this.name = line.substring(0,19);//remove trailing
         this.sellerUsername = line.substring(20,34);
         this.userWithHighestBid = line.substring(35,49);
         this.daysRemaining = Integer.parseInt( line.substring(50,53) );
         this.currentHighestBid = Double.parseDouble ( line.substring(54,60) );
    }

    /**
     * @return the currentHighestBid
     */
    public double getCurrentHighestBid() {
        return currentHighestBid;
    }

    /**
     * @return the daysRemaining
     */
    public int getDaysRemaining() {
        return daysRemaining;
    }

    /**
     * @return the name
     */
    public String getName() {
        return name;
    }

    /**
     * @return the sellerUsername
     */
    public String getSellerUsername() {
        return sellerUsername;
    }

    /**
     * @return the userWithHighestBid
     */
    public String getUserWithHighestBid() {
        return userWithHighestBid;
    }

    /**
     * @param currentHighestBid the currentHighestBid to set
     */
    public void setCurrentHighestBid(double currentHighestBid) {
        this.currentHighestBid = currentHighestBid;
    }

    /**
     * @param daysRemaining the daysRemaining to set
     */
    public void setDaysRemaining(int daysRemaining) {
        this.daysRemaining = daysRemaining;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * @param sellerUsername the sellerUsername to set
     */
    public void setSellerUsername(String sellerUsername) {
        this.sellerUsername = sellerUsername;
    }

    /**
     * @param userWithHighestBid the userWithHighestBid to set
     */
    public void setUserWithHighestBid(String userWithHighestBid) {
        this.userWithHighestBid = userWithHighestBid;
    }
}
