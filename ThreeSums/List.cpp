/*	Nathan Cobb
		01/22/2017
		Linked Lists

		Declares the linked list class functions
*/

#include "List.h"
#include <iostream>

// Constructor
list::list () {
	head = NULL;
	tail = NULL;

	len = 0;
}

// Add an element to the end
void list::push (Node *temp) {
	// If list is empty
	if (len == 0)
	{
		head = temp;
		head->next = NULL;
		tail = head;
		tail->next = NULL;
	}

	// If one element in list
	if (len == 1)
	{
		tail = temp;
		head->next = tail;
	}

	// Otherwise add to end
	else
	{
		tail->next = temp;
		tail = temp;
	}

	// Increment the length
	len++;
}

// Delete the last element
int list::pop () {
	// Store the return value
	int val = tail->value;

	Node temp;
	temp.next = tail;

	// Handle deleting element in single-element list
	if (len == 1)
		head = NULL;
	if (len == 1)
		tail = NULL;

	// Delete
	delete &temp;
	len--;

	return val;
}

// Print the list
void list::print () {
	int n = len;		// Store the length
	Node* temp;
	temp = head;

	// Header
	std::cout << "List:\n  ";

	// Output each element
	while (n > 0)
	{
		std::cout << temp->value << "\n  ";
		temp = temp->next;
		n--;
	}
}

// Destructor
list::~list () {
	while (len > 0)
		pop();

	delete tail;
	delete head;
}