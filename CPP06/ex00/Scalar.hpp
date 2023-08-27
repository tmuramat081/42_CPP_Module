#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>

class Scalar
{
public:
	char as_char;
	int	as_int;
	float as_float;
	double as_double;

	bool char_possible;
	bool int_possible;
	bool float_possible;
	bool double_possible;

	Scalar();
};

std::ostream &operator<<(std::ostream &os, const Scalar &scalar);

#endif
