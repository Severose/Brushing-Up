class list {
	struct Node {
		int* next;

		int value;
	} node;

	Node head;
	Node tail;
	int len;


public:
	list ();
	~list ();
	void push (int);
	void pop ();
	void print (list);
};