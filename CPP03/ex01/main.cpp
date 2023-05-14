#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap("Aqua");

	std::cout << scavTrap << std::endl;

	/** モード移行 */
	scavTrap.guardGate();

	return 0;
}
