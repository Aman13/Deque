
#include <iostream>
#include <stdexcept>

#ifndef Deque_H
#define Deque_H

template <class T>
class Deque	{

public:

	Deque ();

	Deque(const Deque & source);

	~Deque(void);

	Deque & operator= (const Deque & source);

	void insert_front(T value);

	void insert_back(T value);

	T remove_front();

	T remove_back();

	T peek_front()	const;

	T peek_back()	const;

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
	void deepCopy(const Deque & ls);
	void deleteDeque();
	void gaurd()	const;
};

#include "Deque.cpp"

#endif

//////////////////////////////////////////////////
//////////////////////////////////////////////////

/*


#include <iostream>
#include <stdexcept>

template <class T>
class Deque	{

public:
	//Creates a new empty queue.
	Deque () : front(NULL), back(NULL) { 
	}

	//Creates a new queue using data from another.
	//source is the deque whos values are being copied
	Deque(const Deque & source) : front(NULL), back(NULL)	{
		deepCopy(source);
	}

	//Destructor
	~Deque()	{
		deleteDeque();
	}

	//Assigns this deque values from another deque.
	//source is the deque whos values are to be copied to this.
	//return: this.
	Deque & operator= (const Deque & source)	{
		if(this != &source)	{
			deleteDeque();
			deepCopy(source);
		}
		return *this;
	}

	//Inserts a new value at the front of the deque.
	//value, the value to be inserted.
	void insert_front(T value)		{
		//If this is the first item to be inserted into deque
		//must set front and back to this new node.
		if(this->empty())	{
			 this->front = this->back = new Node(value, this->front);
		}
		else	{
			this->front = new Node(value, this->front);
		}
	}

	//Inserts a new value to the back of the deque.
	//value, the value to be inserted.
	void insert_back(T value)	{
		//If this is the first item to be inserted into deque
		//must set front and back to this new node.
		if(this->empty())	{
			this->front = this->back = new Node(value, this->back);
		}
		else	{
			Node* temp = this->back;
			this->back = new Node(value, temp->next);
			temp->next = this->back;
		}
	}

	//Removes the front element of the deque.
	//pre: Deque must not be empty.
	//after: Deque has one less element.
	//return: The front element of the deque.
	T remove_front()	{
		this->gaurd();
		Node* temp = this->front;
		this->front = front->next;
		T storage  = temp->data;
		delete temp;
		return storage;
	}

	//Removes the back element of the deque.
	//pre: Deque must not be empty.
	//after: Deque has one less element.
	//return: The back element of the deque.
	T remove_back()	{
		this->gaurd();
		Node* temp = this->front;
		//If deque only has one object,
		//front and back must be set to NULL
		if(this->front == this->back)	{
			this->front = this->back = NULL;
			T storage = temp->data;
			delete temp;
			return storage;
		}
		//In order to remove the last element without breaking the list
		//must find the second last element.
		while(temp->next != this->back)	{
			temp = temp->next;
		}
		//Once second last element is found, back is now set to to it
		//and temp is set to the element that it points to (last element). The element is stored
		//in a seperate variable, and the node temp points to is destroyed.
		//back element gets reset to point to NULL, making it the new last element.
		this->back = temp;
		temp = temp->next;
		back->next = NULL;
		T storage = temp->data;
		delete temp;
		return storage;
	}

	//Return the first element in the deque.
	//pre: Deque must not be empty.
	//return: The first element.
	T peek_front()	const	{
		this->gaurd();
		return front->data;
	}

	//Return the last element in the deque.
	//pre: Deque must not be empty.
	//return: The last element.
	T peek_back()	const	{
	this->gaurd();
	return back->data;
	}

	//Checks whether deque is empty.
	//return: True if deque is empty, false otherwise. 
	bool empty()	const	{
		return this->front == NULL && this->back == NULL;
	}

	//Count the number of elements in the deque.
	//return: Number of elements in the deque.
	int size()	const	{
		int counter = 0;
		Node* temp = this->front;
		while(temp != NULL)	{
			++counter;
			temp = temp->next;
		}
		return counter;
	}

private:

	class Node	{
	public:
		T data;
		Node* next;

		Node(T value): data(value), next(NULL) {};
		Node(T value, Node* nd): data(value), next(nd) {};
	};

	Node* front;
	Node* back;

	//Checks if deque is empty.
	//Throws runtime error.
	void gaurd()	const	{
		if(this->empty())
			throw std::runtime_error("Deque is empty.");
	}

	//Makes deep copy of the deque.
	//Assigns the deque values from source deque.
	void deepCopy(const Deque & source)	{
		if(source.front == NULL)	{
			this->front = this->back = NULL;
		}
		else	{
			Node* temp = source.front;
			int x = 0;
			while(temp != NULL)	{
				++x;
				this->insert_back(temp->data);
				temp = temp->next;
			}
			delete temp;
		}
	}

	//Deletes the deque.
	//Runs through deque from front to back
	// deleting the nodes until front = NULL
	void deleteDeque()	{
		Node* temp = this->front;
		while(temp != NULL)	{
			temp = front->next;
			delete front;
			front = temp;
		}
		this->front = this->back = NULL;
	}
};

*/