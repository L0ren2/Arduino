#include <iostream>
#include <cassert>
#include "../array.h"

void test_size()
{
	lib::array<int, 10> a;
	assert(a.size() == 10);
}

void test_index()
{
	lib::array<int, 10> a;
	for (int i = 0; i < 10; ++i)
		a[i] = i;
	assert(a[5] == 5);
}

void test_copy()
{
	{
	lib::array<int, 10> a;
	for (int i = 0; i < 10; ++i)
		a[i] = i;
	lib::array<int, 10> b = a;
	for (int i = 0; i < 10; ++i)
	{
		assert(a[i] == b[i]);
		assert(&a != &b);
	}
	}

	{
	lib::array<int, 10> a;
	for (int i = 0; i < 10; ++i)
		a[i] = i;
	lib::array<int, 10> b(a);
	for (int i = 0; i < 10; ++i)
	{
		assert(a[i] == b[i]);
		assert(&a != &b);
	}
	}
}

void test_move()
{
	lib::array<int, 10> a;
	for (int i = 0; i < 10; ++i)
		a[i] = i;
	int* first_elem = &a[0];
	lib::array<int, 10> b = (lib::array<int, 10>&&) a;
	for (int i = 0; i < 10; ++i)
		assert(b[i] == i);
	assert(&b[0] == first_elem);
}

int main()
{
	std::cout << "size" << std::endl;
	test_size();
	std::cout << "index" << std::endl;
	test_index();
	std::cout << "copy" << std::endl;
	test_copy();
	std::cout << "move" << std::endl;
	test_move();
	std::cout << "all tests passed" << std::endl;
}
