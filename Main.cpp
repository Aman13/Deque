#include <iostream>

#include "Deque.h"

int main()	{

	int b = 0;
	Deque a;
	a.insert_front(1);
	a.insert_front(2);
	a.insert_back(5);
	a.insert_front(9);
	a.remove_back();
	b = a.size();
	std::cout << "front contains: " << a.peek_front() << std::endl
	<< "back contains: " << a.peek_back() << std::endl << "size is: " <<
	b << std::endl;

}