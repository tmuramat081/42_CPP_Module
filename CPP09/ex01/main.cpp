#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: wrong argument" << std::endl;
		exit(EXIT_FAILURE);
	}
	try
	{
		RPN rpn;
		std::cout << rpn.calculate(av[1]) << std::endl;
	}
	catch (...)
	{
		std::cerr << "Error" << std::endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}
