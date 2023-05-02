#include "Harl.hpp"

int main()
{
	Harl harl;

	harl.complainFilter("DEBUG");
	harl.complainFilter("INFO");
	harl.complainFilter("WARNING");
	harl.complainFilter("ERROR");
	return 0;
}