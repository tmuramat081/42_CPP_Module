#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"
#include <iostream>

int main()
{
	FlagTrap flagTrap("Ruby");

	std::cout << flagTrap << std::endl;

	/** 攻撃する */
	flagTrap.attack("Bad guy");
	std::cout << flagTrap << std::endl;
	/** ダメージを受ける */
	flagTrap.takeDamage(50);
	std::cout << flagTrap << std::endl;
	/** 体力を回復する */
	flagTrap.beRepaired(25);
	std::cout << flagTrap << std::endl;
	/** ダメージを受ける */
	flagTrap.takeDamage(50);
	std::cout << flagTrap << std::endl;
	/** ハイタッチ */
	flagTrap.highFiveGuys();
	std::cout << flagTrap << std::endl;
	/** ハイタッチ */
	flagTrap.highFiveGuys();
	std::cout << flagTrap << std::endl;

	return 0;
}
