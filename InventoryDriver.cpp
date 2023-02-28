
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include "Car.h"

using namespace std;

void displayMenu();
void addData(vector<Car>&);
void deleteData(vector<Car>&);
void printData(vector<Car>&);

int main() {
	
	int userInput;	
	vector<Car>inventory;
		
	cout << "Welcome to the Car Dealership Inventory Program" << endl;
	cout << endl;
		
	displayMenu();
	cin >> userInput;
		
	while (userInput != 4) {
		 		
		switch (userInput) {
						
			case 1: 
				addData(inventory);
				break;
								
			case 2:
				deleteData(inventory);
				break;
									
			case 3:
				printData(inventory);
				break;
 				
			default:
				break;	
		}	
		displayMenu();
		cin >> userInput;
	}
	return 0;
}

void displayMenu() {
		
	cout << "1. Add a car to inventory" << endl;
	cout << "2. Delete a car from inventory" << endl;
	cout << "3. Print inventory" << endl;
	cout << "4. Exit" << endl;
	cout << endl;
	cout << "Your choice: ";
}

void addData(vector<Car>& inventory) {
		
	string carMake;
	int carPrice;
	
	cout << endl;
	cout << "Type of car: ";
	cin >> carMake;
	cout << "Price of car: ";
	cin >> carPrice;
	cout << endl;
	 	
	Car carEntered{carMake, carPrice};
		
	inventory.push_back(carEntered);
}

void deleteData(vector<Car>& inventory) {
	 	
	string deleteCar;
		
	cout << endl;
	cout << "Type of car to delete: ";
	cin >> deleteCar;
 	
	for (unsigned int i(0); i < inventory.size(); i++) {       
			
		if (deleteCar.compare(inventory[i].getMake()) == 0) {
			 			
			inventory.erase(inventory.begin() + i);
			cout << deleteCar << " deleted from inventory" << endl;
			cout << endl;
			return;
		}
	}	
	cout << "No such car in inventory" << endl;
	cout << endl;
}

void printData(vector<Car>& inventory) {
	
	cout << endl;
	cout << "Make" << setw(20) << "Price" << endl;
	cout << "----" << setw(20) << "-----" << endl;
	
	for (Car cars : inventory) {
		cout << cars.getMake() << setw(20) << cars.getPrice() << endl;
	}
	cout << endl;
}
