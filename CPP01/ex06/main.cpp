#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid arguments." << std::endl;
		return 0;
	}
	Harl harl;
	harl.complainFilter(argv[1]);

	return 0;
}
