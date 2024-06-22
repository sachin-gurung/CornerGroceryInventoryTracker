#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

GroceryTracker::GroceryTracker() {}    // Constructor

void GroceryTracker::loadItems(const string& filename) {
	ifstream inputFile(filename);    // Open the file
	string line;
	
	// Read the file line by line
	while (getline(inputFile,line)) {
		parseLine(line); // Parse each line to update frequencies
	}
	inputFile.close();  // Close the file
}

void GroceryTracker::parseLine(const string& line) {
	if (!line.empty()) {    // ensure the line is not empty
		itemFrequency[line]++;    // Increase the frequency of the item
	}
}

int GroceryTracker::getItemFrequency(const string& item) {
	auto it = itemFrequency.find(item);    // Find the item in the map
	if (it != itemFrequency.end()) {       // Check if the item exists
		return it->second;        // Return the frequency of the item
	}
	return 0; // if item not found, return 0.
}

void GroceryTracker::displayAllItems() {
	for (const auto& entry: itemFrequency) {    // Iterate through the map
		cout << entry.first << " " << entry.second << endl;    // Print each item and its frequency
	}
}

void GroceryTracker::displayHistogram() {
	for (const auto& entry: itemFrequency) {    // Iterate through the map
		cout << entry.first << " ";    // Print the item name
		for (int i = 0; i < entry.second; ++i) {    // Print the asterisks equal to the frequency
			cout << "*";
		}
		cout << endl;
	}
}

void GroceryTracker::writeFrequencyFile(const string& filename) {
	ofstream outputFile(filename);    // Open the output file
	for (const auto& entry: itemFrequency) {    // Iterate through the map
		outputFile << entry.first << " " << entry.second << endl;    // Write each item and it's frequency to the file
	}
	outputFile.close();  // Close the file
}