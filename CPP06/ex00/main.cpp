#include "ScalarConverter.hpp"
#include "Scalar.hpp"
#include <iostream>
#include <cfloat>

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "\033[0;32mUsage: please input one parameter.\033[0m" << std::endl;
		return 0;
	}
	try
	{
		const Scalar s = ScalarConverter::convert(std::string(av[1]));
		std::cout << s << std::endl;
	}
	catch(...)
	{
	}
	return 0;
}
