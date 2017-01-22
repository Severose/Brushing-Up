#include "List.h"

#include <iostream>

list::list () {
	head = NULL;
	tail = NULL;

	len = 0;
}

void list::push (Node *temp) {
	if (len == 0)
	{
		head = temp;
		tail = head;
	}

	if (len == 1)
	{
		head->next = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}

	len++;
}

void list::pop () {
	Node temp;
	temp.next = tail;

	if (len == 1)
		head = NULL;
	if (len == 1)
		tail = NULL;

	delete &temp;
	len--;
}

void list::print (list) {
	Node* temp;
	std::cout << "List:\n  ";
	while (temp != NULL)
	{
		std::cout << temp->value << "\n  ";
		temp = temp->next;
	}
}

list::~list () {
	while (len > 0)
		pop();

	delete tail;
	delete head;
}