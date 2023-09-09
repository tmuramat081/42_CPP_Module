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
	PmergeMe(const PmergeMe &other);

	// Destructor
	~PmergeMe();

	// Operators
	PmergeMe &operator=(const PmergeMe &rhs);
	void sortByVector(int* &elems, size_t len);
	void sortByDeque(int* &elems, size_t len);
	struct comparePair;

private:
	void insertion(std::deque<int> &elems, size_t start, size_t end);
	std::vector<int> _vec;
	std::deque<int> _deq;
};

std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p);
std::ostream& operator<<(std::ostream& os, const std::deque<int> & dq);
std::ostream& operator<<(std::ostream& os, const std::vector<int>& v);

#endif
