#include "easyfind.hpp"
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <string>
#include <iostream>

int main()
{
	// vector
	std::vector<int> vec;
	for(int i = 0; i < 5; ++i)
	{
		vec.push_back(i);
	}
	std::cout << ::easyfind(vec, 1) << std::endl;
	std::cout << ::easyfind(vec, 6) << std::endl;

	// list
	std::list<int> list;
	for (int i = 0; i < 5; ++i)
	{
		list.push_back(i);
	}
	std::cout << ::easyfind(list, 2) << std::endl;

	// array
	std::array<int, 5> arr;
	for (int i = 0; i < 5; ++i)
	{
		arr[i] = i;
	}
	std::cout << ::easyfind(arr, 3) << std::endl;

	// deque
	std::deque<int> deq;
	for (int i = 0; i < 5; ++i)
	{
		deq.push_back(i);
	}
	std::cout << ::easyfind(arr, 4) << std::endl;


	return 0;
}
