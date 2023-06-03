#include "ScalarConverter.hpp"
#include <cctype>
#include <iomanip>

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
	t_scalar s;

	if (param == "nan")
	{
		s =

	}
	else if (isChar(param))
	{
		s = convertFromChar(param.c_str()[0]);
	}
	else if (isInt(param))
	{
		s = convertFromInt(std::stoi(param));
	}
	else if (isFloat(param))
	{
		s = convertFromFloat(std::stof(param));
	}
	else if (isDouble(param))
	{
		s = convertFromDouble(std::stod(param));
	}
	std::cout << s << std::endl;
}

ScalarConverter::t_scalar ScalarConverter::convertFromChar(const char param)
{
	t_scalar s;

	s.as_char = param;
	s.as_int = static_cast<int>(param);
	s.as_float = static_cast<float>(param);
	s.as_double = static_cast<double>(param);
	return s;
}

ScalarConverter::t_scalar ScalarConverter::convertFromInt(const int param)
{
	t_scalar ss;

	std::stringstream ss;
	ss << static_cast<char>(param);
	s.as_int = ss.str();
	s.as_int = param;
	s.as_float = static_cast<float>(param);
	s.as_double = static_cast<double>(param);
	return s;
}

ScalarConverter::t_scalar ScalarConverter::convertFromFloat(const float param)
{
	t_scalar s;

	s.as_char = static_cast<char>(param);
	s.as_int = static_cast<int>(param);
	s.as_float = param;
	s.as_double = static_cast<double>(param);
	return s;
}

ScalarConverter::t_scalar ScalarConverter::convertFromDouble(const double param)
{
	t_scalar s;

	s.as_char = static_cast<char>(param);
	s.as_int = static_cast<int>(param);
	s.as_float = static_cast<float>(param);
	s.as_double = param;
	return s;
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

std::ostream &operator<<(std::ostream &os, const ScalarConverter::t_scalar &s)
{
	std::cout << "char: ";
	if (std::isprint(s.as_char))
	{
		std::cout << "'" << s.as_char << "'" << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: " << s.as_int << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << s.as_float << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << s.as_double;
	return os;
}
