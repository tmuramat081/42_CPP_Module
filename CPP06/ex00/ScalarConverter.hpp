#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
	public:
		// Destructor
		~ScalarConverter();

		// Member functions
		static void convert(const std::string &param);

	private:
		ScalarConverter();

		ScalarConverter(const ScalarConverter &other);
		ScalarConverter & operator=(const ScalarConverter &rhs);

		static bool isChar(const std::string &param);
		static bool isInt(const std::string &param);
		static bool isFloat(const std::string &param);
		static bool isDouble(const std::string &param);

		static bool convertFromChar(const std::string &param);
		static bool convertFromInt(const std::string &param);
		static bool convertFromFloat(const std::string &param);
		static bool convertFromDouble(const std::string &param);
};

#endif
