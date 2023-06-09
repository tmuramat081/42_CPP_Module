#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "\033[0;32mUsage: please input one parameter.\033[0m" << std::endl;
		return 0;
	}
	ScalarConverter::convert(std::string(av[1]));

	return 0;
}
