#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap scavTrap("Aqua");

	std::cout << scavTrap << std::endl;

	/** 攻撃する */
	scavTrap.attack("Bad guy");
	std::cout << scavTrap << std::endl;
	/** ダメージを受ける */
	scavTrap.takeDamage(50);
	std::cout << scavTrap << std::endl;
	/** 体力を回復する */
	scavTrap.beRepaired(25);
	std::cout << scavTrap << std::endl;
	/** ダメージを受ける */
	scavTrap.takeDamage(50);
	std::cout << scavTrap << std::endl;
	/** モード移行 */
	scavTrap.guardGate();
	std::cout << scavTrap << std::endl;
	/** モード移行 */
	scavTrap.guardGate();
	std::cout << scavTrap << std::endl;

	return 0;
}
