#include "Scalar.hpp"
#include <iomanip>
#include <typeinfo>

Scalar::Scalar(): char_possible(false), int_possible(false), float_possible(false), double_possible(false)
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

char Scalar::getChar() const
{
	if (!char_possible)
		throw std::invalid_argument("char is not possible");
	return as_char;
}

int Scalar::getInt() const
{
	if (!int_possible)
		throw std::invalid_argument("int is not possible");
	return as_int;
}

float Scalar::getFloat() const
{
	if (!float_possible)
		throw std::invalid_argument("float is not possible");
	return as_float;
}

double Scalar::getDouble() const
{
	if (!double_possible)
		throw std::invalid_argument("double is not possible");
	return as_double;
}

std::ostream &operator<<(std::ostream &os, const Scalar &scalar)
{
	os << "char: ";
	try
	{
		if (std::isprint(scalar.getChar()))
			os << "'" << scalar.getChar() << "'";
		else
			os << "Non displayable";
	}
	catch (std::invalid_argument &e)
	{
		os << "impossible";
	}
	os << std::endl;

	os << "int: ";
	try
	{
		os << scalar.getInt();
	}
	catch (std::invalid_argument &e)
	{
		os << "impossible";
	}
	os << std::endl;

	os << "float: ";
	try
	{
		os << std::fixed << std::setprecision(1) << scalar.getFloat() << "f";

	}
	catch (std::invalid_argument &e)
	{
		os << "impossible";
	}
	os <<  std::endl;

	os << "double: ";
	try
	{
		os << std::fixed << std::setprecision(1) << scalar.getDouble();
	}
	catch (std::invalid_argument &e)
	{
		os << "impossible";
	}
	return os;
}


