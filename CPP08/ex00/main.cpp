#include "easyfind.hpp"
#include <vector>
#include <list>
#include <string>
#include <iostream>

int main()
{
	std::vector<int> vec;
	for(int i = 0; i < 5; ++i)
	{
		vec.push_back(i);
	}

	std::cout << ::easyfind(vec, 1) << std::endl;

	return 0;
}
