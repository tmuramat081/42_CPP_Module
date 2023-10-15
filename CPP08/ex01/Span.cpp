#include "Span.hpp"
#include <limits>

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
	if (this->getSize() == _n)
	{
		throw std::length_error("Maximum capacity of data reached");
	}
	this->_numbers.insert(number);
}

int Span::shortestSpan() const
{
	if (this->getSize() < 2)
	{
		throw std::range_error("Not enough elements in data for comparison");
	}
	std::multiset<int>::const_iterator first = _numbers.begin();
	std::multiset<int>::const_iterator second = _numbers.begin();
	++second;

	int span = std::numeric_limits<int>::max();
	for (; second != _numbers.cend(); first++, second++)
	{
		// std::cout << *first << ", " << *second << std::endl;
		span = std::min(span, (*second - *first));
	}
	return span;
}

int Span::longestSpan() const
{
	if (this->getSize() < 2)
	{
		throw std::range_error("Not enough elements in data for comparison");
	}
	int first_value = *_numbers.begin();
	int last_value = *_numbers.rbegin();

	return last_value - first_value;
}
