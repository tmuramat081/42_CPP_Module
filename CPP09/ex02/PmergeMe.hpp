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
	// Constructors
	PmergeMe();
	PmergeMe(const PmergeMe &orher);

	// Destructor
	~PmergeMe();

	// Operators
	PmergeMe &operator=(const PmergeMe &rhs);
	void sortByVector(int* &elems, size_t len);
	void sortByDeque(int* &elems, size_t len);
	struct comparePair;

private:
	std::vector<int> _vec;
	std::deque<int> _deq;
};

std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p);
std::ostream& operator<<(std::ostream& os, const std::priority_queue<std::pair<int, int> >& pq);
std::ostream& operator<<(std::ostream& os, const std::vector<int>& v);

#endif
