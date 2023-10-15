#ifndef SortByDeque_HPP
#define SortByDeque_HPP

#include <iostream>
#include <string>
#include <deque>
#include "PmergeMe.hpp"

class SortByDeque : public PmergeMe
{
public:
	template<class RandomIt>
	static void sort(RandomIt first, RandomIt last);

private:
	template<class RandomIt>
	static void mergeInsertSort(RandomIt first, RandomIt last);

	SortByDeque();
	~SortByDeque();
};

#include "SortByDeque.tpp"

#endif
