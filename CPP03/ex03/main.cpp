#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\033[0;93m-- Parent class --\033[0;39m" << std::endl;
	ClapTrap clapTrap("Ai");
	std::cout << clapTrap << std::endl;
	std::cout << std::endl;

	std::cout << "\033[0;93m-- Child class --\033[0;39m" << std::endl;
	ScavTrap scavTrap("Aqua");
	std::cout << scavTrap << std::endl;
	FlagTrap flagTrap("Ruby");
	std::cout << flagTrap << std::endl;
	std::cout << std::endl;

	std::cout << "\033[0;93m-- Grand child class --\033[0;39m" << std::endl;
	DiamondTrap diamondTrap("Idle");
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
	/** モード移行 */
	diamondTrap.guardGate();
	std::cout << diamondTrap << std::endl;
	/** ハイタッチ */
	diamondTrap.highFiveGuys();
	std::cout << diamondTrap << std::endl;
	/** 私は誰？ */
	diamondTrap.whoAmI();
	std::cout << diamondTrap << std::endl;


	return 0;
}
