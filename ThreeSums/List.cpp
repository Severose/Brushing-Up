#include "List.h"

#include <iostream>
#include <iterator>

list::list () {
	head = NULL;
	tail = NULL;

	len = 0;
}

void list::push (int n) {
	Node temp;
	temp.value = n;

	if (len == 0)
		head = temp;
		tail = head;

	if (len == 1)
		head.next = temp;
		tail = temp;
	else
		tail.next = temp;
		tail = temp;

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
	std::cout << "List:\n  ";
	for (iterator::iterator<list> i = head; i != NULL; ++i)
		std::cout << i->value << "\n  ";
}

list::~list () {
	while (len > 0)
		pop();

	delete tail;
	delete head;
}