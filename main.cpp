#include <iostream>
#include "GroceryTracker.h"
using namespace std;

// Function to display the menu
void displayMenu() {
	cout << "1. Search of an item" << endl;
	cout << "2. Display all items" << endl;
	cout << "3. Display histogram" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your choice: ";
}

int main() {
	GroceryTracker tracker;    // Create an instance of GroceryTracker
	tracker.loadItems("CS210_Project_Three_Input_File.txt");    // Load items from the input file
	tracker.writeFrequencyFile("frequency.dat");    // Write the frequency data to the backup file

	int choice;  // Variable to store user's menu choice

	do {
		displayMenu();    // Displays the menu
		cin >> choice;    // Get user's choice

		// Input validation
		if (cin.fail()) {
			cin.clear();    // clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Ignore the rest of the input
			cout << "Invalid input. Please enter a number between 1 and 4." << endl;
		}

		if (choice == 1) {
			string item;
			cout << "Enter item name: ";
			cin >> item;
			cout << "Frequency of " << item << ": " << tracker.getItemFrequency(item) << endl;  // Display the frequency
		} 
		else if (choice == 2) {
			tracker.displayAllItems();   // Display all items and their frequency
		}
		else if (choice == 3) {
			tracker.displayHistogram();    // Display the histrogram of item frequency
		}
	} while (choice != 4);    // Continue until user chooses 4 to exit

	return 0;    // Exit the program
}
