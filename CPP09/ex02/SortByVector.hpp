#ifndef SortByVector_HPP
#define SortByVector_HPP

#include <iostream>
#include <string>
#include <vector>
#include "PmergeMe.hpp"

class SortByVector : public PmergeMe
{
public:
	template<class RandomIt>
	static void sort(RandomIt first, RandomIt last);

private:
	template<class RandomIt>
	static void mergeInsertSort(RandomIt first, RandomIt last);

	SortByVector();
	~SortByVector();
};

#include "SortByVector.tpp"

#endif
