
#include <iostream>
#include <stdexcept>

class Deque	{

public:

	Deque (void);

	//Deque(const Deque & source);

	void insert_front(int value);

	void insert_back(int value);

	int remove_front();

	int remove_back();

	int peek_front()	const;

	int peek_back()	const;

	bool empty()	const;

	int size()	const;



private:

	class Node	{
	public:
		int data;
		Node* next;

		Node(int value): data(value), next(NULL) {};
		Node(int value, Node* nd): data(value), next(nd) {};
	};

	Node* front;
	Node* back;


};