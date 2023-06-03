#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
public:
	// Destructor
	~ScalarConverter();

	// Member functions
	static void convert(const std::string &param);
	typedef struct s_scalar
	{
		std::string as_char;
		std::string as_int;
		std::string as_float;
		std::string as_double;
	} t_scalar;

private:
	ScalarConverter();

	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &rhs);

	static bool isChar(const std::string &param);
	static bool isInt(const std::string &param);
	static bool isFloat(const std::string &param);
	static bool isDouble(const std::string &param);

	static void putScalarParams(t_scalar s);

	static t_scalar convertFromChar(const char param);
	static t_scalar convertFromInt(const int param);
	static t_scalar convertFromFloat(const float param);
	static t_scalar convertFromDouble(const double param);
};

std::ostream &operator<<(std::ostream &os, const ScalarConverter::t_scalar &s);

#endif
