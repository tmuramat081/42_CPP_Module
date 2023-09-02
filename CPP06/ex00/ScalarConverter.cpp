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
		s.setChar(charVal);
		s.setInt(charVal);
		s.setFloat(charVal);
		s.setDouble(charVal);
	}
	else if (isInt(param))
	{
		int intVal = std::atoi(param.c_str());
		s.setChar(intVal);
		s.setInt(intVal);
		s.setFloat(intVal);
		s.setDouble(intVal);
	}
	else if (isFloat(param))
	{
		float floatVal = static_cast<float>(std::atof(param.c_str()));
		s.setChar(floatVal);
		s.setInt(floatVal);
		s.setFloat(floatVal);
		s.setDouble(floatVal);
	}
	else if (isDouble(param))
	{
		double doubleVal = std::atof(param.c_str());
		s.setChar(doubleVal);
		s.setInt(doubleVal);
		s.setFloat(doubleVal);
		s.setDouble(doubleVal);
	}
	return s;
}

bool ScalarConverter::isChar(const std::string &value)
{
	return value.length() == 1 && !std::isdigit(value[0]);
}

bool ScalarConverter::isInt(const std::string &value)
{
	if (value.empty())
	{
		return false;
	}
	std::istringstream iss(value);
	int intVal;
	iss >> intVal;
	return !iss.fail() && iss.eof();
}

bool ScalarConverter::isFloat(const std::string &value)
{
	if (value.empty())
	{
		return false;
	}
	else if (value == "nanf" || value == "+inff" || value == "-inff")
	{
		return true;
	}
	char lastChar = value[value.length() - 1];
	if (lastChar == 'f' || lastChar == 'F')
	{
		std::istringstream iss(value.substr(0, value.length() - 1));
		float floatVal;
		iss >> floatVal;
		return !iss.fail() && iss.eof();
	}
	return false;
}

bool ScalarConverter::isDouble(const std::string &value)
{
	if (value.empty())
	{
		return false;
	}
	else if (value == "nan" || value == "+inf" || value == "-inf")
	{
		return true;
	}
	std::istringstream iss(value);
	double doubleVal;
	iss >> doubleVal;
	return !iss.fail() && iss.eof();
}


