class list {

public:
	struct Node {
		Node* next;

		int value;
	};

	list ();
	~list ();
	void push (Node*);
	int pop ();
	void print ();

private:
	Node* head;
	Node* tail;
	int len;
};