#ifndef Deque_H
#define Deque_H

#include <iostream>
#include <string>
#include <stdexcept>

template <class T>

class Deque	{

public:
	//Default constructor.
	Deque ();
	//Copy constructor.
	Deque(const Deque & source);
	//Destructor.
	~Deque();
	//Overloaded assignment operator.
	Deque & operator= (const Deque & source);
	//Inserts a value to the front of the deque.
	void insert_front(T value);
	//Inserts a value to the back of the deque.
	void insert_back(T value);
	//Removes the front element of the deque.
	T remove_front();
	//Removes the back element of the deque.
	T remove_back();
	//Returns the value of the front element.
	T peek_front()	const;
	//Returns the value of the back element.
	T peek_back()	const;
	//Check whether the deque is empty.
	bool empty()	const;
	//Returns the size of the deque.
	int size()	const;

private:
	//Node class, defines what a node contains.
	class Node	{
	public:
		int data;
		Node* next;

		Node(int value): data(value), next(NULL) {};
		Node(int value, Node* nd): data(value), next(nd) {};
	};

	Node* front;
	Node* back;
	//Assigns a deque data from another deque.
	void deepCopy(const Deque & source);
	//Deletes the deque.
	void deleteDeque();
	//Checks if deque is empty
	//throws a runtime error if it is
	void gaurd()	const;
};

#include "Deque.cpp"

#endif
