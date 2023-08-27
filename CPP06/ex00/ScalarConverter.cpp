#include "ScalarConverter.hpp"
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>
#include <cmath>
#include "Scalar.hpp"

// Constructors
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
	return ;
}

// Destructor
ScalarConverter::~ScalarConverter() {}

// Operators
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}

Scalar ScalarConverter::convert(const std::string &param)
{;
	Scalar s;

	// char, int, float, double
	if (isChar(param))
	{
		char charVal = param[0];
		s.as_char = charVal;
		s.as_int = static_cast<int>(charVal);
		s.as_float = static_cast<float>(charVal);
		s.as_double = static_cast<double>(charVal);
	}
	else if (isInt(param))
	{
		int intVal = std::atoi(param.c_str());
		s.as_char =  static_cast<char>(intVal);
		s.as_int = intVal;
		s.as_float = static_cast<float>(intVal);
		s.as_double = static_cast<double>(intVal);
	}
	else if (isFloat(param))
	{
		float floatVal = static_cast<float>(std::atof(param.c_str()));
		s.as_char =  static_cast<char>(floatVal);
		s.as_int = static_cast<int>(floatVal);
		s.as_float = floatVal;
		s.as_double = static_cast<double>(floatVal);
	}
	else if (isDouble(param))
	{
		double doubleVal = std::atof(param.c_str());
		s.as_char =  static_cast<char>(doubleVal);
		s.as_int = static_cast<int>(doubleVal);
		s.as_float = static_cast<float>(doubleVal);
		s.as_double = doubleVal;
	}
	else
	{
		s.char_possible = s.int_possible = s.double_possible = s.float_possible = false;
	}
	return s;
}

bool ScalarConverter::isChar(const std::string &value)
{
	return value.length() == 1 && !std::isdigit(value[0]);
}

bool ScalarConverter::isInt(const std::string &value)
{
	std::istringstream iss(value);
	int intVal;
	iss >> intVal;
	return !iss.fail() && iss.eof();
}

bool ScalarConverter::isFloat(const std::string &value)
{
	std::istringstream iss(value);
	float intVal;
	iss >> intVal;
	return !iss.fail() && iss.eof();
}

bool ScalarConverter::isDouble(const std::string &value)
{
	std::istringstream iss(value);
	double intVal;
	iss >> intVal;
	return !iss.fail() && iss.eof();
}
