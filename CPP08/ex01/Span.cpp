#include "Span.hpp"

// Constructors
Span::Span() : _n(0) {}

Span::Span(const unsigned int n) : _n(n) {}

Span::Span(const Span &other) : _n(other._n) {}

// Destructor
Span::~Span() {}

// Operators
Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		(void)rhs;
	}
	return *this;
}

// Getters / setters
size_t Span::getSize() const
{
	return this->_numbers.size();
}

void Span::addNumber(const int number)
{
	if (this->getSize() + 1 == _n)
	{
		return;
	}
	this->_numbers.insert(number);
}

int Span::shortestSpan() const
{
	std::multiset<int>::const_iterator first = _numbers.begin();
	std::multiset<int>::const_iterator second = _numbers.begin();
	++second;

	int min = 0;
	for (; second != _numbers.cend(); first++, second++)
	{
		min = std::max(min, (*second - *first));
	}
	return min;
}

int Span::longestSpan() const
{
	int first_value = *_numbers.begin();
	int last_value = *_numbers.rbegin();

	return last_value - first_value;
}
