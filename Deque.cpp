#ifndef _DEQUE_H_
#include <stdexcept>
//#include "Deque.h"

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