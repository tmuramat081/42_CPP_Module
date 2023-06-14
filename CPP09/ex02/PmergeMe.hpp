#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <queue>

class PmergeMe
{
public:
	// Constructors
	PmergeMe();
	PmergeMe(const PmergeMe &orher);

	// Destructor
	~PmergeMe();

	// Operators
	PmergeMe &operator=(const PmergeMe &rhs);
	void sort(int* &elems, size_t len);

private:
	std::priority_queue<int> _pq;
	void sortOnePair(std::pair<int, int> &p);
};

std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p);

#endif
