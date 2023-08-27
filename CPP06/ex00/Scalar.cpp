#include "Scalar.hpp"
#include <iomanip>

Scalar::Scalar(): char_possible(true), int_possible(true), float_possible(true), double_possible(true)
{
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
