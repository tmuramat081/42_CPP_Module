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
	Span(const unsigned int n);
	Span(const Span &other);

	// Destructor
	~Span();

	// Operators
	Span &operator=(const Span &rhs);

	// Member functions
	void addNumber(const int number);
	int shortestSpan()const;
	int longestSpan()const;

	// Getters / setters
	size_t getSize() const;

private:
	std::multiset<int> _numbers;
	const unsigned int _n;
};

#endif
