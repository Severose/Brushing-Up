#include <iostream>
#include "List.cpp"


int main () {
	list l;

	l.push(1);
	l.push(2);
	l.push(3);
	l.push(4);
	l.push(5);
	l.push(6);
	l.pop();

	l.print();
}