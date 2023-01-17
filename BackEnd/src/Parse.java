package src;

import java.util.ArrayList;
import java.io.*;
import java.util.Scanner;

/**
 * Description: This class parses all of the transactions from the Daily
 * 	Transaction File
 * Inputs: The users and the available items
 * Outputs: N/A
 */
public class Parse {
	 /**
	 * Description: reads file line by line into target ArrayList
	 * Inputs: filename and the ArrayList for the lines to be
	 * 	placed in
	 * Outputs: N/A
	 */
	public static void readFile(String origin, ArrayList<String> target) {
		try {
			File in = new File(origin);
			Scanner scanner = new Scanner(in);
			while (scanner.hasNextLine()) {
				target.add(scanner.nextLine());
			}
			scanner.close();
		}
		catch(FileNotFoundException e){
			System.out.println("ERROR: file not found");
			e.printStackTrace();
			System.exit(0);
		}
	}


	/**
	 * Description: This method takes the transaction string and processes
	 * 	the trasnaction based on witch type it is
	 * Inputs: The transaction string
	 * Outputs: N/A
	 */
	public static boolean applyTransaction(String line, ArrayList<User> users, ArrayList<Item> items){
		String print = "";
		print += line.charAt(0);
		print += line.charAt(1);

		//logout
		if (Integer.parseInt(print) == 0){
			System.out.println("End of session");
		}
		//apply create
		else if (Integer.parseInt(print) == 1){
			if(create(line, users)) {
				return true;
			}
		}
		//apply delete
		else if (Integer.parseInt(print) == 2){
			System.out.println("Delete");
			// send to delete function
		}
		//apply advertise
		else if (Integer.parseInt(print) == 3){
			System.out.println("Advertise");
			// send to advertise function
		}
		//apply bid
		else if (Integer.parseInt(print) == 4){
			System.out.println("Bid");
			// send to bid function
		}
		//apply refund
		else if (Integer.parseInt(print) == 5){
			System.out.println("Refund");
			// send to refund function
		}
		//apply addCredit
		else if (Integer.parseInt(print) == 6){
			System.out.println("addCredit");
			// send to addCredit function
		}
		else {
			System.out.println("Transaction does not exist");
		}
		return false;
	}

	/**
	 * Description: add a new user to the users array
	 * Inputs: Trasnaction string
	 * Outputs: N/A
	 */
	private static boolean create(String newUser, ArrayList<User> users) {
		try {
			// first create new user
			User userToAdd = new User();
			userToAdd.setUsername(newUser.substring(3, 19));
			userToAdd.setUserType(newUser.substring(20, 23));
			userToAdd.setAvailableCredit(Double.parseDouble(newUser.substring(24)));

			// check if the user already exists
			for(User user : users) {
				if(user.getUsername() == userToAdd.getUsername()){
					System.err.println("User" + userToAdd.getUsername() + "already Exists!");
					return false;
				}
			}

			// add into users array if the user does not already exist
			users.add(userToAdd);
			return true;

		} catch (Exception e) {
			System.err.println(e.getMessage());
			return false;
		}
	}

	/**
	 * Description: deletes a user from users array
	 * Inputs: Transaction string
	 * Outputs: N/A
	 */
	private static boolean delete(String deleteUser){
		System.out.println(deleteUser);
		return false;
	}

	/**
	 * Description: creates a new item in the item array
	 * Inputs: Transaction string
	 * Outputs: N/A
	 */
	private static boolean advertise(String newItem){
		System.out.println(newItem);
		return false;
	}

	/**
	 * Description: updates an item's current highest bid
	 * Inputs: Transaction string
	 * Outputs: N/A
	 */
	private static boolean bid(String newBid){
		System.out.println(newBid);
		return false;
	}

	/**
	 * Description: lowers seller's credits and increases buyer's credits
	 * 	by the refund amount
	 * Inputs: Transaction string
	 * Outputs: N/A
	 */
	private static boolean refund(String newRefund){
		System.out.println(newRefund);
		return false;
	}

	/**
	 * Description: updates user's credit
	 * Inputs: Transaction string
	 * Outputs: N/A
	 */
	private static boolean addCredit(String credit){
		// updates user's credit
		System.out.println(credit);
		return false;
	}
}
