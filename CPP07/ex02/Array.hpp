#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
public:
	// Constructors
	Array();
	Array(unsigned int n);
	Array(const Array &other);

	// Destructor
	~Array();

	// Operator
	Array &operator=(const Array &rhs);
	T &operator[](size_t index);

	// Member functions
	size_t size() const;

private:
	T *_array;
	size_t _n;
};

#include "Array.tpp"

#endif
