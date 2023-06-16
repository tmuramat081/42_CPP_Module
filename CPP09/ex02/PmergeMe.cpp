#include "PmergeMe.hpp"
#include <utility>
#include <queue>
#include <deque>

// Constructors
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->_pq = other._pq;
}

// Destructor
PmergeMe::~PmergeMe() {}

// Operators
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		this->_pq = rhs._pq;
	}
	return *this;
}

struct PmergeMe::comparePair
{
	bool operator()(std::pair<int, int> const &p1, std::pair<int, int> const &p2)
	{
		// 'greater' comparison for min heap
		return p1.first > p2.first;
	}
};

void PmergeMe::sortByPqueue(int *&elems, size_t len)
{
	// 奇数の場合は余剰要素を別に持つ
	int individual;
	size_t size = len;

	if (len & 1)
	{
		individual = elems[len-1];
		size = len - 1;
	}

	// ペアの要素に分割する
	for (size_t i = 0, j = 0; i < size; i += 2, ++j)
	{
		int& first = elems[i], second = elems[i + 1];
		// ペアの要素をソートし、大きい要素を小さい要素の数列にマージする
			_pq.push(first);
		if (first < second) {
			_pq.push(second);
		} else {
			_pq.push(second);
			_pq.push(first);
		}
	}
	//　余剰要素をマージする
	if (len & 1)
	{
		_pq.push(individual);
	}
	for (size_t i = 0; i < len; i++)
	{
		elems[i] = _pq.top(); _pq.pop();
	}
}

void PmergeMe::sortByVector(int *&elems, size_t len)
{
	// 奇数の場合は余剰要素を別に持つ
	int individual;
	size_t size = len;

	if (len & 1)
	{
		individual = elems[len-1];
		size = len - 1;
	}

	// ペアの要素に分割する
	for (size_t i = 0, j = 0; i < size; i += 2, ++j)
	{
		int& first = elems[i], second = elems[i + 1];
		// ペアの要素をソートし、大きい要素を小さい要素の数列にマージする
		if (first < second) {
			_pq.push(first);
			_pq.push(second);
		} else {
			_pq.push(second);
			_pq.push(first);
		}
	}
	//　余剰要素をマージする
	if (len & 1)
	{
		_pq.push(individual);
	}
	for (size_t i = 0; i < len; i++)
	{
		elems[i] = _pq.top(); _pq.pop();
	}
}

std::ostream &operator<<(std::ostream &os, const std::pair<int, int> &p)
{
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

std::ostream &operator<<(std::ostream &os, const std::priority_queue<std::pair<int, int> > &pq)
{
	std::priority_queue<std::pair<int, int> > pq_copy = pq;

	while (!pq_copy.empty())
	{
		std::cout << pq_copy.top() << ' ';
		pq_copy.pop();
	}
	return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<int> &v)
{
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	return os;
}
