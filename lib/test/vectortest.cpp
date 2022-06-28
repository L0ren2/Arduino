#include <cassert>
#include <iostream>
#include "../vector.h"

void test_simple_push_back()
{
	lib::vector<int> v;
	v.push_back(42);
}

void test_size() 
{
	lib::vector<int> v;
	assert(v.size() == 0);
	v.reserve(5);
	assert(v.size() == 0);
	v.push_back(42);
	assert(v.size() == 1);
	v.push_back(42);
	assert(v.size() == 2);
	v.push_back(42);
	assert(v.size() == 3);
}

void test_capacity_reserve() 
{
	lib::vector<int> v;
	assert(v.capacity() == 0);
	v.reserve(5);
	assert(v.capacity() == 5);
	v.reserve(25);
	assert(v.capacity() == 25);
	v.reserve(2);
	assert(v.capacity() == 25);
}

void test_resize() 
{
	lib::vector<int> v;
	v.reserve(5);
	for (int i = 0; i < 5; ++i)
		v.push_back(i);
	assert(v.capacity() == 5);
	assert(v.size() == 5);
	v.push_back(42);
	assert(v.capacity() > 5);
	assert(v.size() == 6);
}

void test_lots_of_push_back()
{
	size_t big_num = 1000000;
	lib::vector<int> v;
	for(size_t i = 0; i < big_num; ++i)
		v.push_back(i);
	assert(v.size() == big_num);
	assert(v.capacity() >= big_num);
}

void test_copy()
{
	{
	lib::vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);
	lib::vector<int> w = v;
	for (int i = 0; i < 10; ++i)
		assert(v[i] == w[i]);
	assert(&v != &w);
	}

	{
	lib::vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);
	lib::vector<int> w(v);
	for (int i = 0; i < 10; ++i)
		assert(v[i] == w[i]);
	assert(&v != &w);
	}
}

void test_move()
{
	int* first_elem;
	lib::vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);
	first_elem = &v[0];
	lib::vector<int> w = std::move(v);
	for (int i = 0; i < 10; ++i)
		assert(w[i] == i);
	assert(&w[0] == first_elem);
}
	
int main()
{
	std::cout << "simple push_back" << std::endl;
	test_simple_push_back();
	std::cout << "size" << std::endl;
	test_size();
	std::cout << "capacity_reserve" << std::endl;
	test_capacity_reserve();
	std::cout << "resize" << std::endl;
	test_resize();
	std::cout << "lots_of_push_back" << std::endl;
	test_lots_of_push_back();
	std::cout << "copy" << std::endl;
	test_copy();
	std::cout << "move" << std::endl;
	test_move();
	std::cout << "executed all tests." << std::endl;
	return 0;
}
