/*	Nathan Cobb
		01/22/2017
		Linked Lists

		Main
*/

#include <iostream>
#include "List.h"

// Print menu
void printMenu();

int main () {
	list l;							// The list
	int selection = 1;	// Menu selection

	// Main loop
	while(selection > 0 && selection <= 3)
	{
		printMenu();						// Print menu
		std::cin >> selection;	// Get the user's selection

		// Create a new node to work with
		list::Node* temp = new list::Node();

		// Menu structure
		switch(selection)
		{
			// 1 - Adding element
			case 1:	temp->next = NULL;
							std::cout << "Enter a value: ";
							std::cin >> temp->value;
							l.push(temp);
							break;

			// 2 - Deleting element
			case 2:	std::cout << "Deleting " << l.pop() << "\n";
							break;

			// 3 - Printing the list
			case 3:	l.print();
							break;

			// Default, exit
			default:
							break;
		}
	}

	return 0;
}

// Print the menu to get the user's selection
void printMenu()
{
	std::cout << "\nMenu:\n1 - Add\n2 - Delete\n3 - Print All\n0 - Exit\nSelection: ";
}