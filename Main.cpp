#include <iostream>
#include <string>

#include "Deque.h"
#define assert(x, msg) if (!(x)) throw msg;

void test_size()	{
	Deque test;
	test.insert_front(1);
	test.insert_front(2);
	test.insert_back(3);
	assert(test.size() == 3, "Size should be 3");
}

void test_peek()	{
	Deque test;
	test.insert_front(1);
	test.insert_back(3);
	test.insert_back(9);
	test.insert_back(12);
	test.insert_front(24);
	assert(test.peek_front() == 24, "Front should contain 24");
	assert(test.peek_back() == 12, "Back should be 12");
}

void test_remove()	{
	Deque test;
	test.insert_front(3);
	test.insert_front(9);
	test.insert_back(4);
	test.insert_back(1);
	test.remove_front();
	test.remove_back();
	assert(test.peek_front() == 3, "Front should be 3");
	assert(test.peek_back() == 4, "Back should be 4");
}
void test_empty()	{
	Deque test;
	assert(test.empty() == true, "Deque should be empty");
}

void test_copy()	{
	Deque test;
	Deque copy;
	test.insert_front(1);
	test.insert_front(2);
	test.insert_front(3);
	copy = test;
	test.remove_front();
	test.remove_back();
	assert(copy.size() == 3, "size should be 3");
}

int main()	{

	try	{
		test_size();
		test_peek();
		test_remove();
		test_empty();
		test_copy();
	}
	catch(const char* msg) {
		std::cout << "error: " << msg << std::endl;
		return 1;
	}
	return 0;
}