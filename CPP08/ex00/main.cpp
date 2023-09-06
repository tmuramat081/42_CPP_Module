#include "easyfind.hpp"
#include <vector>
#include <list>
#include <forward_list>
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

	// deque
	std::deque<int> deq;
	for (int i = 0; i < 5; ++i)
	{
		deq.push_back(i);
	}
	std::cout << ::easyfind(deq, 2) << std::endl;

	// forward_list
	std::forward_list<int> flist;
	for (int i = 4; i >= 0; --i)
	{
		flist.push_front(i);
	}
	std::cout << ::easyfind(flist, 3) << std::endl;

	// list
	std::list<int> list;
	for (int i = 0; i < 5; ++i)
	{
		list.push_back(i);
	}
	std::cout << ::easyfind(list, 4) << std::endl;

	// array
	std::array<int, 5> arr;
	for (int i = 0; i < 5; ++i)
	{
		arr[i] = i;
	}
	std::cout << ::easyfind(arr, 5) << std::endl;
	return 0;
}
