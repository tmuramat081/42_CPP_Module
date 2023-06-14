#include "PmergeMe.hpp"
#include <utility>

// Constructors
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->_pq = other._pq;
}

// Destructor
PmergeMe::~PmergeMe(){}

// Operators
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		this->_pq = rhs._pq;
	}
	return *this;
}


void PmergeMe::sort(int *&elems, size_t len)
{
	// 奇数の場合は最後の要素を個別に持つ
	int individual;
	if (len & 1)
	{
		individual = elems[len];
		--len;
	}

	// ペアの要素に分割する
	std::pair<int, int> p;
	for (size_t i = 0; i < len; i += 2)
	{
		p = std::make_pair(elems[i], elems[i + 1]);
		std::cout << p << std::endl;
	}

	// ペアの要素内でソート
	this->sortOnePair(p);

	

	return ;
}

void PmergeMe::sortOnePair(std::pair<int, int> &p)
{
	if (p.first > p.second)
	{
		std::swap(p.first, p.second);
	}
}

std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p)
{
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
