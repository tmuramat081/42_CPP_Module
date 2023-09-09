#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <ctime>

void sort(int *elems, size_t len)
{
	clock_t start = clock();

	std::cout << "Before:\t";
	for (size_t i = 0; i < len; ++i)
	{
		std::cout << elems[i];
		if (i != len)
			std::cout << ' ';
	}
	std::cout << std::endl;

	PmergeMe pm;
	pm.sortByDeque(elems, len);

	std::cout << "After:\t";
	for (size_t i = 0; i < len; ++i)
	{
		std::cout << elems[i];
		if (i != len)
			std::cout << ' ';
	}
	std::cout << std::endl;

	clock_t end = clock();
	double duration = (end - start) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of\t" << len << " elements with std::priority_queue : " << duration << " us" << std::endl;
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Error: wrong argument" << std::endl;
		exit(EXIT_FAILURE);
	}
	char **args = &av[1];
	size_t len = ac - 1;
	try
	{
		int *elems = new int[len];
		for (size_t i = 0; i < len; ++i)
		{
			elems[i] = std::stoi(args[i]);
		}
		sort(elems, len);
	}
	catch (...)
	{
		std::cerr << "Error" << std::endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}
