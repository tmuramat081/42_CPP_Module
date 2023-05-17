#include "Replace.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Invalid arguments." << std::endl;
		return 0;
	}

	Replace replace(argv[1], argv[2], argv[3]);
	replace.replaceAll();

	return 0;
}
