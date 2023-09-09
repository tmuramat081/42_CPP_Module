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

void PmergeMe::sortByDeque(int *&elems, size_t start, size_t)
{
	std::deque<int> deq(elems, elems + len);
	size_t start = 0;
	size_t end = len - 1;

	std::deque<int> main;
	std::deque<int> sub;

	// 奇数の場合は余剰要素を別に持つ
	int individual;
	size_t size = len;

	if (len & 1)
	{
		individual = elems[len - 1];
		size = len - 1;
	}

	// ペアの要素に分割する
	for (size_t i = 0, j = 0; i < size; i += 2, ++j)
	{
		int& first = elems[i], second = elems[i + 1];
		// ペアの要素をソートし、大きい要素を小さい要素の数列にマージする
		if (first < second)
		{
			main.push_back(first);
			sub.push_back(second);
		} else
		{
			sub.push_back(second);
			main.push_back(first);
		}
	}
	//　余剰要素をマージする
	if (len & 1)
	{
		main.push_back(individual);
	}
	insertion(main, 0, main.size() - 1);

	for (size_t i = 0, j = 0; i < len; i++, j += 2)
	{
		elems[i] = deq.front(); deq.pop_front();
	}
	for (size_t i = 0; i < len; ++i)
	{
		for (size_t j = end; j >= start; --j)
		{
			if (elems[i] <= sub[i])
			{
				arr[i + 1] = pend;
				break;
			}
			arr[i + 1] = arr[i];
		}
	}
}

// void PmergeMe::sortByVector(int *&elems, size_t len)
// {
// 	// 奇数の場合は余剰要素を別に持つ
// 	int individual;
// 	size_t size = len;

// 	if (len & 1)
// 	{
// 		individual = elems[len - 1];
// 		size = len - 1;
// 	}

// 	// ペアの要素に分割する
// 	for (size_t i = 0, j = 0; i < size; i += 2, ++j)
// 	{
// 		int& first = elems[i], second = elems[i + 1];
// 		// ペアの要素をソートし、大きい要素を小さい要素の数列にマージする
// 		if (first < second) {
// 			_vec.push_back(first);
// 			_vec.push_back(second);
// 		} else {
// 			_vec.push_back(second);
// 			_vec.push_back(first);
// 		}
// 	}
// 	//　余剰要素をマージする
// 	if (len & 1)
// 	{
// 		_vec.push(individual);
// 	}
// 	for (size_t i = 0; i < len; i++)
// 	{
// 		elems[i] = _vec.top(); _vec.pop();
// 	}
// }

std::ostream &operator<<(std::ostream &os, const std::pair<int, int> &p)
{
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

std::ostream &operator<<(std::ostream &os, const std::deque<int> &dq)
{
	std::deque<int> dq_copy = dq;

	while (!dq_copy.empty())
	{
		std::cout << dq_copy[0] << ' ';
		dq_copy.pop_front();
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
