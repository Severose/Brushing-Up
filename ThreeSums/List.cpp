#include "List.h"

#include <iostream>

list::list () {
	head = NULL;
	tail = NULL;

	len = 0;
}

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

	len++;
}

int list::pop () {
	int val = tail->value;

	Node temp;
	temp.next = tail;

	if (len == 1)
		head = NULL;
	if (len == 1)
		tail = NULL;

	delete &temp;
	len--;

	return val;
}

void list::print () {
	int n = len;
	Node* temp;
	temp = head;
	std::cout << "List:\n  ";
	while (n > 0)
	{
		std::cout << temp->value << "\n  ";
		temp = temp->next;
		n--;
	}
}

list::~list () {
	while (len > 0)
		pop();

	delete tail;
	delete head;
}