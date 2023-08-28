#include "Scalar.hpp"
#include <iomanip>
#include <typeinfo>

Scalar::Scalar(): char_possible(true), int_possible(true), float_possible(true), double_possible(true)
{
}

Scalar::~Scalar()
{
}

Scalar::Scalar(const Scalar &other)
{
	*this = other;
}

Scalar &Scalar::operator=(const Scalar &rhs)
{
	if (this != &rhs)
	{
		char_possible = rhs.char_possible;
		int_possible = rhs.int_possible;
		float_possible = rhs.float_possible;
		double_possible = rhs.double_possible;
		as_char = rhs.as_char;
		as_int = rhs.as_int;
		as_float = rhs.as_float;
		as_double = rhs.as_double;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Scalar &scalar)
{
	os << "char: ";
	if (scalar.char_possible)
	{
		if (std::isprint(scalar.as_char))
			os << scalar.as_char;
		else
			os << "Non displayable";
	}
	else
		os << "impossible";
	os << std::endl;

	os << "int: ";
	if (scalar.int_possible)
		os << scalar.as_int;
	else
		os << "impossible";
	os <<  std::endl;

	os << "float: ";
	if (scalar.float_possible)
		os << std::fixed << std::setprecision(1) << scalar.as_float << "f";
	else
		os << "impossible";
	os <<  std::endl;

	os << "double: ";
	if (scalar.double_possible)
		os << scalar.as_double;
	else
		os << "impossible";

	return os;
}


