#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	DiamondTrap diamondTrap("Diamond");

	std::cout << diamondTrap << std::endl;

	/** 攻撃する */
	diamondTrap.attack("Bad guy");
	std::cout << diamondTrap << std::endl;
	/** ダメージを受ける */
	diamondTrap.takeDamage(50);
	std::cout << diamondTrap << std::endl;
	/** 体力を回復する */
	diamondTrap.beRepaired(25);
	std::cout << diamondTrap << std::endl;
	/** ダメージを受ける */
	diamondTrap.takeDamage(50);
	std::cout << diamondTrap << std::endl;
	/** 私は誰？ */
	diamondTrap.highFiveGuys();
	std::cout << diamondTrap << std::endl;

	return 0;
}
