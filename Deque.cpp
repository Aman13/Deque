#ifdef Deque_H

#include <string>
#include <stdexcept>
//#include "Deque.h"

//Default constructor.
//Creates a new empty deque.
template <class T>
Deque<T>::Deque () : front(NULL), back(NULL) { 
}

//Destructor.
//Memory associated with the deque is de-allocated.
template <class T>
Deque<T>::~Deque()	{
	deleteDeque();
}

//Copy constructor.
//Creates a new deque using data from another.
template <class T>
Deque<T>::Deque(const Deque & source) : front(NULL), back(NULL)	{
	deepCopy(source);
}

//Overloaded assignment operator.
//Param: Source, is the deque to be copied to the calling object.
//Post: Copies source to the calling object. Returns calling object.
template <class T>
Deque<T> & Deque<T>::operator= (const Deque & source)	{
	if(this != &source)	{
		deleteDeque();
		deepCopy(source);
	}
	return *this;
}

//Inserts a element into the deque at the front.
//Param: Value to be inserted.
//Post: Value is inserted at the front of the deque.
template <class T>
void Deque<T>::insert_front(T value)		{
	//If this is the first item to be inserted into deque
	//must set front and back to this new node.
	if(this->empty())	{
		 this->front = this->back = new Node(value, this->front);
	}
	else	{
		this->front = new Node(value, this->front);
	}
}

//Inserts a element into the deque at the back.
//Param: Value to be inserted.
//Post: Value is inserted at the back of the deque.
template <class T>
void Deque<T>::insert_back(T value)	{
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
//Pre: Deque must not be empty.
//Post: The front element is removed
//and the value is returned.
template <class T>
T Deque<T>::remove_front()	{
	this->gaurd();
	Node* temp = this->front;
	this->front = front->next;
	T storage  = temp->data;
	delete temp;
	return storage;
}

//Removes the back elemnt of the deque.
//Pre: Deque must not be empty.
//Post: The back element is removed
//and the value is returned.
template <class T>
T Deque<T>::remove_back()	{
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

//Return the first element of the deque.
//Pre: Deque must not be empty.
//Post: Returns the front element of the deque.
template <class T>
T Deque<T>::peek_front()	const	{
	this->gaurd();
	return front->data;
}

//Return the back element of the deque.
//Pre: Deque must not be empty.
//Post:Returns the front element of the deque.
template <class T>
T Deque<T>::peek_back()	const	{
	this->gaurd();
	return back->data;
}

//Checks whether deque is empty.
//Post: Returns true if deque is empty, false otherwise
template <class T>
bool Deque<T>::empty()	const	{
	return this->front == NULL && this->back == NULL;
}

//Counts the number of elements in the deque.
//Post: Returns the number of elements in the deque.
template <class T>
int Deque<T>::size()	const	{
	int counter = 0;
	Node* temp = this->front;
	while(temp != NULL)	{
		++counter;
		temp = temp->next;
	}
	return counter;
}

//Checks if deque is empty.
//Throws runtime error if it is.
template <class T>
void Deque<T>::gaurd()	const	{
	if(this->empty())
		throw std::runtime_error("Deque is empty.");
}

//Removes all the elements from the deque and
//deallocates dynamic memory associated.
//Post:Deque is empty.
template <class T>
void Deque<T>::deleteDeque()	{
	Node* temp = this->front;
	while(temp != NULL)	{
		temp = front->next;
		delete front;
		front = temp;
	}
	this->front = this->back = NULL;
}

//Makes a deep copy of the deque.
//Param:Source is the deque to be copied
//Pre: Calling deque is empty.
//Post: Deque contents are identical to source.
template <class T>
void Deque<T>::deepCopy(const Deque & source)	{
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

#endif