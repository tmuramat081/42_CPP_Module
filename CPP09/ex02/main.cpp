#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <ctime>

static void sortTest(std::vector<int> elems)
{
	clock_t start = clock();

	std::cout << "Before:\t";
	for (size_t i = 0; i < elems.size(); ++i)
	{
		std::cout << elems[i];
		if (i != elems.size())
			std::cout << ' ';
	}
	std::cout << std::endl;

	PmergeMe::sort(elems.begin(), elems.end());

	std::cout << "After:\t";
	for (size_t i = 0; i < elems.size(); ++i)
	{
		std::cout << elems[i];
		if (i != elems.size())
			std::cout << ' ';
	}
	std::cout << std::endl;

	clock_t end = clock();
	double duration = (end - start) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of\t" << elems.size() << " elements with std::priority_queue : " << duration << " us" << std::endl;
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
		std::vector<int> elems;
		for (size_t i = 0; i < len; ++i)
		{
			elems.push_back(std::stoi(args[i]));
		}
		sortTest(elems);
	}
	catch (...)
	{
		std::cerr << "Error" << std::endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}
