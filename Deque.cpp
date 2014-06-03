
#include <stdexcept>
//#include "Deque.h"
#ifdef Deque_H


template <class T>
Deque<T>::Deque () : front(NULL), back(NULL) { 
}

template <class T>
Deque<T>::~Deque()	{
	deleteDeque();
}

template <class T>
Deque<T>::Deque(const Deque & source) : front(NULL), back(NULL)	{
	deepCopy(source);
}

template <class T>
Deque<T> & Deque<T>::operator= (const Deque & source)	{
	if(this != &source)	{
		deleteDeque();
		deepCopy(source);
	}
	return *this;
}

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

template <class T>
T Deque<T>::remove_front()	{
	this->gaurd();
	Node* temp = this->front;
	this->front = front->next;
	T storage  = temp->data;
	delete temp;
	return storage;
}

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

template <class T>
T Deque<T>::peek_front()	const	{
	this->gaurd();
	return front->data;
}

template <class T>
T Deque<T>::peek_back()	const	{
	this->gaurd();
	return back->data;
}

template <class T>
bool Deque<T>::empty()	const	{
	return this->front == NULL && this->back == NULL;
}

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

template <class T>
void Deque<T>::gaurd()	const	{
	if(this->empty())
		throw std::runtime_error("Deque is empty.");
}

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


//////////////////////////////////////
///////////////////////////////////////
/////////////////////////////////////
//////////////////////////////////////




/*
#include <stdexcept>
#include "Deque.h"

template <class T>
Deque<T>::Deque()	{
	front = back = NULL;
}

template <class T>
Deque<T>::~Deque()	{
	deleteDeque();
}

template <class T>
Deque<T>::Deque(const Deque & source)	{
	deepCopy(source);
}

template <class T>
Deque<T> & Deque<T>::operator= (const Deque & source)	{
	if(this != &source)	{
		deleteDeque();
		deepCopy(source);
	}
	return *this;
}

template <class T>
void Deque<T>::insert_front(T value)	{
	if(this->front == NULL && this->back == NULL)	{
		 this->front = this->back = new Node(value, this->front);
	}
	else	{
		Node* temp = this->front;
		this->front = new Node(value, temp);
	}
}

template <class T>
void Deque<T>::insert_back(T value)	{
	if(this->front == NULL && this->back == NULL)	{
		this->front = this->back = new Node(value, this->back);
	}
	else	{
		Node* temp = this->back;
		this->back = new Node(value, temp->next);
		temp->next = this->back;
	}
}

template <class T>
T Deque<T>::remove_front()	{
	if(this->front == NULL && this->back == NULL)	{
		throw std::runtime_error("deque is empty");
	}
	Node* temp = this->front;
	this->front = front->next;
	T storage  = temp->data;
	delete temp;
	return storage;
}

template <class T>
T Deque<T>::remove_back()	{
	if(this->front == NULL && this->back == NULL)	{
		throw std::runtime_error("deque is empty");
	}
	Node* temp = this->front;
	if(this->front == this->back)	{
		this->front = this->back = NULL;
		T storage = temp->data;
		delete temp;
		return storage;
	}
	while(temp->next != this->back)	{
		temp = temp->next;
	}
	this->back = temp;
	temp = temp->next;
	back->next = NULL;
	T storage = temp->data;
	delete temp;
	return storage;
}

template <class T>
T Deque<T>::peek_front()	const{
	if(this->front == NULL && this->back == NULL)	{
		throw std::runtime_error("deque is empty");
	}
	return front->data;
}

template <class T>
T Deque<T>::peek_back()	const{
	if(this->front == NULL && this->back == NULL)	{
		throw std::runtime_error("deque is empty");
	}
	return back->data;
}

template <class T>
bool Deque<T>::empty()	const{
	if(this->front == NULL && this->back == NULL)	{
		return true;
	}
	return false;
}

template <class T>
int Deque<T>::size()	const{
	int counter = 0;
	Node* temp = this->front;
	while(temp != NULL)	{
		++counter;
		temp = temp->next;
	}
	return counter;
}

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

template <class T>
void Deque<T>::deepCopy(const Deque & source)	{
	if(source.front == NULL)	{
		this->front = NULL;
		this->back = NULL;
	}
	else	{
		Node* temp = source.front;
		while(temp != NULL)	{
			this->insert_back(temp->data);
			temp = temp->next;
		}
	}
}

*/