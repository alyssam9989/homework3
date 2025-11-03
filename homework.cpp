#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main() {
	const string FILE_NAME = "report.txt";

	cout << "===========================================" << endl;
	cout << "Welcome to Alyssa's Baking Cost Calculator!" << endl;
	cout << "===========================================" << endl;

	string recipeName;
	int numberOfDesserts = 0;
	double costPerDessert = 0.00;
	double totalCost = 0.00;
	double budget = 0.00;

	//prompt user for information
	cout << "Enter the name of your recipe: ";
	getline(cin, recipeName);

	cout << "Enter the quantity you plan to bake: ";
	cin >> numberOfDesserts;

	if (cin.fail() || numberOfDesserts <= 0) {
		cout << "Invalid input. Please restart and enter a positive, whole number.\n";
		return 1;
	}

	cout << "Enter the cost per dessert quantity ($): ";
	cin >> costPerDessert;

	cout << "What is your overall budget?: ";
	cin >> budget;

	while (cin.fail() || costPerDessert <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid cost. Please enter a positive nunber: $";
		cin >> costPerDessert;
	}

	//calculate cost to make specific amount of dessert
	totalCost = numberOfDesserts * costPerDessert;

	cout << "Total cost: $" << totalCost << endl;

	//print menu
	int choice;
	cout << "\nMenu: \n";
	cout << "1. View Summary\n";
	cout << "2. Budget Recommendation\n";
	cout << "3. Exit\n";
	cin >> choice;

	ofstream report(FILE_NAME);
	report << fixed << setprecision(2);

	//print based on user input
	switch (choice) {
	case 1:
		cout << "\nBaking Summary:\n";
		cout << left << setw(20) << "Recipe" << right << setw(15) << "Desserts" << setw(15) << "Total Cost\n";
		cout << left << setw(20) << recipeName << right << setw(15) << numberOfDesserts << setw(15) << totalCost << "\n";

		report << "Baking Summary\n";
		report << left << setw(20) << "Recipe" << right << setw(15) << "Desserts" << setw(15) << "Total Cost\n";
		report << left << setw(20) << recipeName << right << setw(15) << numberOfDesserts << setw(15) << totalCost << "\n";
		cout << "\nReport saved to " << FILE_NAME << endl;
		break;

	case 2:
		if (totalCost <= budget && numberOfDesserts >= 5) {
			cout << "Great job! You're using your budget wisely!\n";
		}
		else if (totalCost > budget && numberOfDesserts < 3) {
			cout << "You might want to adjust your ingredients, bake fewer items.\n";
		} 
		else {
			cout << "Keep tracking your costs in order to optimize your budget!\n";
		}
		break;

	case 3: 
		cout << "Goodbye! Happy Baking!\n";
		break;

	default: 
		cout << "Invalid menu option.\n";
		break;
	}

	report.close();
	return 0;
}
