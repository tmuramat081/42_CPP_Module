#include "SortByVector.hpp"
#include "SortByDeque.hpp"
#include <iostream>
#include <string>
#include <ctime>

static void sortTest(std::vector<int> elems)
{
	// 元の配列を表示
	std::cout << "Before:\t";
	for (size_t i = 0; i < elems.size(); ++i)
	{
		std::cout << elems[i];
		if (i != elems.size())
			std::cout << ' ';
	}
	std::cout << std::endl;

	// std::vectorを用いたソート
	std::vector<int> e1 = elems;
	clock_t start;
	start = clock();
	SortByVector::sort(e1.begin(), e1.end());
	clock_t end;
	end = clock();
	double duration1 = (end - start) * 1000000.0 / CLOCKS_PER_SEC;

	// std::dequeを用いたソート
	std::vector<int> e2 = elems;
	start = clock();
	SortByDeque::sort(e2.begin(), e2.end());
	end = clock();
	double duration2 = (end - start) * 1000000.0 / CLOCKS_PER_SEC;

	// std::sort
	SortByVector::sort(elems.begin(), elems.end());

	// ソート結果に誤りがないか確認
	if (e1 != elems || e2 != elems || e1 != e2)
	{
		std::cerr << "Error: different results" << std::endl;
		exit(EXIT_FAILURE);
	}

	// ソート結果を表示
	std::cout << "After:\t";
	for (size_t i = 0; i < e1.size(); ++i)
	{
		std::cout << e1[i];
		if (i != e1.size())
			std::cout << ' ';
	}
	std::cout << std::endl;

	// ソートにかかった時間を表示
	std::cout << "Time to process a range of\t" << elems.size() << " elements with std::vector : " << duration1 << " us" << std::endl;
	std::cout << "Time to process a range of\t" << elems.size() << " elements with std::deque : " << duration2 << " us" << std::endl;
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Error: wrong argument" << std::endl;
		exit(EXIT_FAILURE);
	}
	try
	{
		std::vector<int> elems;
		for (int i = 1; i < ac; ++i)
		{
			std::size_t idx = 0;
			std::string arg = av[i];
			int num = std::stoi(av[i], &idx);
			if (num < 0 || arg.size() != idx)
				throw std::invalid_argument("Error: invalid argument");
			elems.push_back(num);
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
