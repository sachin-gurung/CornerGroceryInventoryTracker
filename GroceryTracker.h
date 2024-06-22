#pragma once
#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>
using namespace std;

// GroceryTracker class declaration
class GroceryTracker{
public:
	GroceryTracker(); // Constructor

	// Function to load items from a file
	void loadItems(const string& filename);

	// Function to get frequency of a specific item
	int getItemFrequency(const string& item);

	// Function to display all items with their frequencies
	void displayAllItems();

	// Function to display a histogram of items with their frequencies
	void displayHistogram();

	// Function to write frequencies to a file for backup
	void writeFrequencyFile(const string& filename);

private:
	map<string, int> itemFrequency;  // Map to store item frequencies
	void parseLine(const string& line);  // Helper function to parse a line and update item frequencies
};

#endif

