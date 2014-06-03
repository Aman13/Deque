#include <iostream>
#include <stdexcept>

template <class T>
class Deque	{

public:

	Deque () : front(NULL), back(NULL) { }

	Deque(const Deque & source)	{
		Deque();
		std::cout << "deepy copy" << std::endl;
		deepCopy(source);
	}

	~Deque()	{
		deleteDeque();
	}

	Deque & operator= (const Deque & source)	{
		std::cout << "entering overloaded operator" << std::endl;
		if(this != &source)	{
			deleteDeque();
			deepCopy(source);
		}
		return *this;
	}

	void insert_front(T value)		{
		if(this->empty())	{
			 this->front = this->back = new Node(value, this->front);
		}
		else	{
			this->front = new Node(value, this->front);
		}
	}

	void insert_back(T value)	{
		if(this->empty())	{
			this->front = this->back = new Node(value, this->back);
		}
		else	{
			Node* temp = this->back;
			this->back = new Node(value, temp->next);
			temp->next = this->back;
		}
	}

	T remove_front()	{
		this->gaurd();
		Node* temp = this->front;
		this->front = front->next;
		T storage  = temp->data;
		delete temp;
		return storage;
	}

	T remove_back()	{
		this->gaurd();
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

	T peek_front()	const	{
		this->gaurd();
		return front->data;
	}

	T peek_back()	const	{
	this->gaurd();
	return back->data;
	}

	bool empty()	const	{
		return this->front == NULL && this->back == NULL;
	}

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

	void gaurd()	const	{
		if(this->empty())
			throw std::runtime_error("Deque is empty.");
	}

	void deepCopy(const Deque & source)	{
		std::cout << "entering void deepCopy" << std::endl;
		if(source.front == NULL)	{
			std::cout << "source front = NULL" << std::endl;
			this->front = NULL;
			this->back = NULL;
		}
		else	{
			std::cout << "source front = stuff" << std::endl;
			Node* temp = source.front;
			std::cout << "node temp is set, entering while loop" << std::endl;
			int x = 0;
			while(temp != NULL)	{
				std::cout <<"looping around: " << x << std::endl;
				++x;
				this->insert_back(temp->data);
				std::cout <<" leaving inser_back" << std::endl;
				temp = temp->next;
			}
			delete temp;
			std::cout<< "leaving while loop" << std::endl;
		}
	}
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
