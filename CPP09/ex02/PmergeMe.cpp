#include "PmergeMe.hpp"
#include <utility>
#include <queue>

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

void PmergeMe::sort(int *&elems, size_t len)
{
	// 奇数の場合は最後の要素を別に持つ
	int individual;
	size_t size = len;

	if (len & 1)
	{
		individual = elems[len];
		size = len - 1;
	}

	// ペアの要素に分割する
	for (size_t i = 0, j = 0; i < size; i += 2, ++j)
	{
		int first = elems[i], second = elems[i + 1];
		// ペアの小さい値が先になるように交換する
		if (first > second)
			std::swap(first, second);
		std::pair<int, int> p = std::make_pair(first, second);
		// 優先度付きキューに格納する
		this->_pq.push(p);
	}

	// std::cout << _pq << std::endl;

	// 二分法でペアの大きい値をマージする
	std::vector<int> list;
	list.reserve(len);

	while (!_pq.empty())
	{
		std::pair<int, int> p = _pq.top();
		_pq.pop();
		list.push_back(p.first);
		std::vector<int>::iterator it = std::lower_bound(list.begin(), list.end(), p.second);
		list.insert(it, p.second);
		std::cout << "After insertion: ";
for (size_t i = 0; i < list.size(); i++) {
    std::cout << list[i] << " ";
}
std::cout << std::endl;
	}
	std::cout << list << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		elems[i] = list[i];
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
