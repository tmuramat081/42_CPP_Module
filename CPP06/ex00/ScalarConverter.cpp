#include "ScalarConverter.hpp"
#include <cctype>

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

void ScalarConverter::convert(const std::string &param)
{
	if (isChar(param))
	{
		std::cout << param << std::endl;
	}
	else if (isInt(param))
	{
		std::cout << stoi(param) << std::endl;
	}
	else if (isFloat(param))
	{
		std::cout << stof(param) << std::endl;
	}
	else if (isDouble(param))
	{
		std::cout << stod(param) << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string &param)
{
	return (param.length() == 1 && std::isalpha(param.c_str()[0]));
}

bool ScalarConverter::isInt(const std::string &param)
{
	size_t pos;

	try
	{
		std::stoi(param, &pos);
		return param.length() == pos;
	}
	catch (...)
	{
		return false;
	}
}

bool ScalarConverter::isFloat(const std::string &param)
{
	size_t pos;

	if (param.back() != 'f')
	{
		return false;
	}
	try
	{
		std::stof(param, &pos);
		return param.length() == pos + 1;
	}
	catch (...)
	{
		return false;
	}
}

bool ScalarConverter::isDouble(const std::string &param)
{
	size_t pos;

	try
	{
		std::stod(param, &pos);
		return param.length() == pos;
	}
	catch (...)
	{
		return false;
	}
}

bool ScalarConverter::convertFromChar(const std::string &param)
{
	std::cout << "char: " << c <<
}
