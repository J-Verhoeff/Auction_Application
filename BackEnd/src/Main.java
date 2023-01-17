package src;

/**
 * CSCI 3060 Course Project Winter 2020
 * Auction Application Back-end
 * Authors: Joshua Verhoeff, Michael van Dalen, Spencer Denford
 * Date: 2020-03-15
 *
 * This software application is the back-end component for the auction
 * application. This will take in 3 files as input: the combined Daily
 * Trasnaction file, The old current user accounts file, and the old available
 * Items file. Then this software will process each transaction that occured
 * and update the current user accounts and available items files accordingly.
 *
 * The program will also check for any items that have ended the auction time
 * and update the files accordingly. During a run any errors will be printed
 * to the command line. Finally, at the end of a successful run the program
 * will create updated user accounts and avialable items files with all the
 * required changes to be used by the front-end for the next day.
 */

import java.io.*;
import java.util.ArrayList;


/**
 * Description: This is the main class for the system back-end
 * Inputs: filenames as command line arguments
 * Outputs: N/A
 */
public class Main {
	private static String dtf_target = "default_files/transactions.txt";	//transactions file name
	private static String uaf_target = "default_files/users.txt";			//user accounts file name
	private static String aif_target = "default_files/items.txt";			//available items file name
	private static ArrayList<String> dtf_data = new ArrayList<>();			//stores transactions
	private static ArrayList<String> uaf_data = new ArrayList<>();			//stores users
	private static ArrayList<String> aif_data = new ArrayList<>();			//stores items
	private static ArrayList<User> users = new ArrayList<>();
	private static ArrayList<Item> items = new ArrayList<>();


	/**
	 * Description: updates seller's credits, the buyer's credits, and deletes
	 * 	them auction item from the items array
	 * Inputs: The item where the auction has ended
	 * Outputs: N/A
	*/
	private void endAuction(Item itemToEnd){

	}

	/**
	 * Description: since all of the transactions are now done, and all the
	 * 	transaction function have just been updating the users and items
	 * 	arrays, this function updates the old items.txt, users.txt and
	 * 	transaction.txt
	 * Inputs: N/A
	 * Outputs: New current user accounts file and avialable items file
	 */
	private void writeOut(){

	}

	/**
	 * Description: src.Main method for system back-end
	 * Inputs: Command line arguments
	 * Outputs: N/A
	 */

	public static void main(String[] args) throws IOException{
		//command line argument handling
		if (args.length !=0 && args.length !=3) {
			System.out.println("ERROR: to use default files, 0 args\n"
					+ "else, arg1-> transactions, arg2-> users, arg3-> items");
			System.exit(0);
		}
		//settings target files to command line arguments
		if (args.length==3) {
			dtf_target = args[0];
			uaf_target = args[1];
			aif_target = args[2];
		}
		//stores daily transactions as strings in arraylist
		Parse.readFile(dtf_target,dtf_data);
		//stores user accounts as strings in arraylist
		Parse.readFile(uaf_target,uaf_data);
		//stores available items as strings in arraylist
		Parse.readFile(aif_target,aif_data);

		//stores user strings into arraylist of users
		for (String userInfo : uaf_data){
			User user = new User(userInfo);
			users.add(user);
		}
		//stores item strings into arraylist of items
		for (String itemInfo : aif_data){
			Item item = new Item(itemInfo);
			items.add(item);
		}
		//calls all transactions
		for (String transaction : dtf_data){
			Parse.applyTransaction(transaction,users,items);
		}

		System.out.println("done");
		System.exit(0);
	}

}
