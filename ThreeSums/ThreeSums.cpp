#include <iostream>
#include "List.cpp"

int main () {
	list l;

	for (int i = 1; i <= 6; ++i)
	{
		Node temp;
		temp->value = i
		l.push(&temp);
	}

	l.pop();

	l.print();

	return 0;
}