
#include "Deque.h"

Deque::Deque()	{
	front = back = NULL;
}

void Deque::insert_front(int value)	{
	if(this->front == NULL && this->back == NULL)	{
		 this->front = this->back = new Node(value, this->front);
	}
	else	{
		Node* temp = this->front;
		this->front = new Node(value, temp);
	}
}

void Deque::insert_back(int value)	{
	if(this->front == NULL && this->back == NULL)	{
		this->front = this->back = new Node(value, this->back);
	}
	else	{
		Node* temp = this->back;
		this->back = new Node(value, temp->next);
		temp->next = this->back;
	}
}

int Deque::remove_front()	{
	Node* temp = this->front;
	this->front = front->next;
	return temp->data;
}

int Deque::remove_back()	{
	Node* temp = this->front;
	while(temp->next != this->back)	{
		temp = temp->next;
	}
	this->back = temp;
	temp = temp->next;
	back->next = NULL;
	return temp->data;
}

int Deque::peek_front()	const{
	return front->data;
}

int Deque::peek_back()	const{
	return back->data;
}

bool Deque::empty()	const{
	if(this->front == NULL && this->back == NULL)	{
		return true;
	}
	return false;
}

int Deque::size()	const{
	int counter = 0;
	Node* temp = this->front;
	while(temp != NULL)	{
		++counter;
		temp = temp->next;
	}
	return counter;

}