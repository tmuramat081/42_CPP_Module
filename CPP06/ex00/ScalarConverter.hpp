#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
	public:
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);

		// Destructor
		~ScalarConverter();

		// Operators
		ScalarConverter & operator=(const ScalarConverter &assign);

		// Function Members
		char convert(const std::string &param);
		int convert(const std::string &param);
		float convert(const std::string &param);
		double convert(const std::string &param);


	private:

};

#endif