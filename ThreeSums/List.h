/*	Nathan Cobb
		01/22/2017
		Linked Lists

		Defines linked list class and associated structures
*/

// List class
class list {

public:
	// Node struct
	struct Node {
		Node* next;				// Next node in list

		int value;				// Node value
	};

	list ();						// Constructor
	~list ();						// Destructor
	void push (Node*);	// Add element
	int pop ();					// Delete element
	void print ();			// Print list

private:
	Node* head;					// First element
	Node* tail;					// Last element
	int len;						// Length of list
};