
#include "Deque.h"

Deque::Deque()	{
	front = back = NULL;
}

/*Deque::~Deque(void)	{
	deleteDeque();
}

Deque::Deque(const Deque & source)	{
	deepCopy(source);
}

Deque & Deque::operator= (const Deque & source)	{
	if(this != &source)	{
		deleteDeque();
		deepCopy(source);
	}
	return *this;
}
*/
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
	if(this->front == NULL && this->back == NULL)	{
		throw std::runtime_error("deque is empty");
	}
	Node* temp = this->front;
	this->front = front->next;
	int storage  = temp->data;
	delete temp;
	return storage;
}

int Deque::remove_back()	{
	if(this->front == NULL && this->back == NULL)	{
		throw std::runtime_error("deque is empty");
	}
	Node* temp = this->front;
	if(this->front == this->back)	{
		this->front = this->back = NULL;
		int storage = temp->data;
		delete temp;
		return storage;
	}
	while(temp->next != this->back)	{
		temp = temp->next;
	}
	this->back = temp;
	temp = temp->next;
	back->next = NULL;
	int storage = temp->data;
	delete temp;
	return storage;
}

int Deque::peek_front()	const{
	if(this->front == NULL && this->back == NULL)	{
		throw std::runtime_error("deque is empty");
	}
	return front->data;
}

int Deque::peek_back()	const{
	if(this->front == NULL && this->back == NULL)	{
		throw std::runtime_error("deque is empty");
	}
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

void Deque::deleteDeque()	{
	Node* temp = this->front;
	while(temp != NULL)	{
		temp = front->next;
		delete front;
		front = temp;
	}
	this->front = this->back = NULL;
}

void Deque::deepCopy(const Deque & source)	{
	if(source.front == NULL & source.back == NULL)	{
		this->front == NULL;
		this->back == NULL;
	}
	if(source.front != NULL)
	{
		Node* temp = source.front;
		this->front = new Node(temp->data, temp->next);
		temp = temp->next;
		if(temp == NULL)	{
			this->back = this->front;
		}
		while(temp->next !=NULL)	{
			this->back = new Node(temp->data, temp->next);
			temp = temp->next;
		}
	}
}