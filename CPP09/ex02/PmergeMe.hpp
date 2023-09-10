#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <deque>

class PmergeMe
{
public:
	template<class RandomIt>
	static void sort(RandomIt first, RandomIt last);

private:
	template<class RandomIt>
	static void mergeInsertSort(RandomIt first, RandomIt last);

	PmergeMe();
	~PmergeMe();
};

#include "PmergeMe.tpp"

#endif
