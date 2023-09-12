#ifndef PMERGEME_HPP
#define PMERGEME_HPP
class PmergeMe
{
public:
	template<class RandomIt>
	void sort(RandomIt first, RandomIt last);
};

#include "PmergeMe.tpp"

#endif
