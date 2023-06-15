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
	void sort(int* &elems, size_t len);
	struct comparePair;

private:
	void sortOnePair(std::pair<int, int> &p);
	void insertionPairs(std::priority_queue<std::pair<int, int> > p, size_t len);
	void insert(std::pair<int, int> &p, std::priority_queue<std::pair<int, int> > ps, size_t len);
	std::priority_queue<std::pair<int, int> > _pq;
};

std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p);
std::ostream& operator<<(std::ostream& os, const std::priority_queue<std::pair<int, int> >& pq);
std::ostream& operator<<(std::ostream& os, const std::vector<int>& v);

#endif
