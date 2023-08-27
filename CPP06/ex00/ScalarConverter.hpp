#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include "Scalar.hpp"

class ScalarConverter
{
public:
	// Destructor
	~ScalarConverter();

	// Member functions
	static Scalar convert(const std::string &param);

private:
	ScalarConverter();

	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &rhs);

	static bool isChar(const std::string &param);
	static bool isInt(const std::string &param);
	static bool isFloat(const std::string &param);
	static bool isDouble(const std::string &param);

	static std::string convertToChar(const std::string &param);
	static std::string convertInt(const std::string &param);
	static std::string convertFloat(const std::string &param);
	static std::string convertDouble(const std::string &param);
};

#endif
