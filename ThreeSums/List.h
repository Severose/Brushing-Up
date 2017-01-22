class list {
	struct Node {
		Node* next;

		int value;
	} node;

	Node* head;
	Node* tail;
	int len;


public:
	list ();
	~list ();
	void push (Node*);
	void pop ();
	void print (list);
};