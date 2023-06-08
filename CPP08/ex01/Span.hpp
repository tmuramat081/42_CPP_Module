#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <set>

class Span
{
public:
	// Constructors
	Span();
	Span(const Span &other);

	// Destructor
	~Span();

	// Operators
	Span &operator=(const Span &rhs);

	// Member functions
	void addNumber(int number);
	int shortestSpan()const;
	int longestSpan()const;

private:
	std::multiset<int> _numbers;
};

#endif