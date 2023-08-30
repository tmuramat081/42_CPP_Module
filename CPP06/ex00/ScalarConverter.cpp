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
		s.setValues(charVal);
	}
	else if (isInt(param))
	{
		int intVal = std::atoi(param.c_str());
		s.setValues(intVal);
	}
	else if (isFloat(param))
	{
		float floatVal = static_cast<float>(std::atof(param.c_str()));
		s.setValues(floatVal);
	}
	else if (isDouble(param))
	{
		double doubleVal = std::atof(param.c_str());
		s.setValues(doubleVal);
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
	if (value == "nanf" || value == "+inff" || value == "-inff")
	{
		return true;
	}
	std::istringstream iss(value);
	float intVal;
	iss >> intVal;
	return !iss.fail() && iss.eof();
}

bool ScalarConverter::isDouble(const std::string &value)
{
	if (value == "nan" || value == "+inf" || value == "-inf")
	{
		return true;
	}
	std::istringstream iss(value);
	double intVal;
	iss >> intVal;
	return !iss.fail() && iss.eof();
}


