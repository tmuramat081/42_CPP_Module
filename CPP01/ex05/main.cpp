#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		return 0;
	}
	Harl harl;

	harl.complainFilter(argv[1]);
	return 0;
}