#include <iostream>

#include "Deque.h"

int main()	{

	int b = 0;
	int c = 0;
	Deque a;
	a.insert_front(1);
	a.insert_front(2);
	a.insert_back(5);
	a.insert_front(9);
	a.remove_back();
	a.remove_back();
	a.remove_back();
	a.remove_back();
//	a.remove_back();
	a.insert_back(2);
	a.insert_back(3);
	a.insert_front(99);
	a.insert_back(5);
	a.insert_back(12);
	a.insert_back(13);
	b = a.size();
	c = a.remove_back();
	int f = a.remove_back();

	std::cout << "front contains: " << a.peek_front() << std::endl
	<< "back contains: " << a.peek_back() << std::endl << "size is: " <<
	b << std::endl << " removed item was: " << c << std::endl <<
	"removed item was: " << f << std::endl;

}