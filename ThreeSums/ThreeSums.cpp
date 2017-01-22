#include <iostream>
#include "List.h"

void printMenu();

int main () {
	list l;
	int selection = 1;

	while(selection > 0 && selection <= 3)
	{
		printMenu();
		std::cin >> selection;

		list::Node* temp = new list::Node();

		switch(selection)
		{
			case 1:	temp->next = NULL;
							std::cout << "Enter a value: ";
							std::cin >> temp->value;
							l.push(temp);
							break;
			case 2:	std::cout << "Deleting " << l.pop() << "\n";
							break;
			case 3:	l.print();
							break;
			default:
							break;
		}
	}

	return 0;
}

void printMenu()
{
	std::cout << "\nMenu:\n1 - Add\n2 - Delete\n3 - Print All\n0 - Exit\nSelection: ";
}