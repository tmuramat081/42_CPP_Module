#include "PmergeMe.hpp"
#include <utility>
#include <queue>
#include <deque>

// Constructors
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->_deq = other._deq;
	this->_vec = other._vec;
}

// Destructor
PmergeMe::~PmergeMe() {}

// Operators
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		this->_deq = rhs._deq;
		this->_vec = rhs._vec;
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

void PmergeMe::sortByDeque(int *&elems, size_t len)
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
			_deq.push_back(first);
		if (first < second) {
			_deq.push_back(second);
		} else {
			_deq.push_back(second);
			_deq.push_back(first);
		}
	}
	//　余剰要素をマージする
	if (len & 1)
	{
		_deq.push_back(individual);
	}
	for (size_t i = 0; i < len; i++)
	{
		elems[i] = _deq.top(); _deq.pop_front();
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
			_vec.push_back(first);
			_vec.push_back(second);
		} else {
			_vec.push_back(second);
			_vec.push_back(first);
		}
	}
	//　余剰要素をマージする
	if (len & 1)
	{
		_vec.push(individual);
	}
	for (size_t i = 0; i < len; i++)
	{
		elems[i] = _vec.top(); _vec.pop();
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
