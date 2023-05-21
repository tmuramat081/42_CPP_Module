#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::string name("Ai");
	ClapTrap crapTrap(name);

	std::cout << "[ " << crapTrap << " ]" << std::endl;

	/** 攻撃する */
	crapTrap.attack("Bad guy");
	crapTrap.attack("Bad guy");
	crapTrap.attack("Bad guy");
	crapTrap.attack("Bad guy");
	crapTrap.attack("Bad guy");
	std::cout << "[ " << crapTrap << " ]" << std::endl;

	/** ダメージを受ける */
	crapTrap.takeDamage(5);
	std::cout << "[ " << crapTrap << " ]" << std::endl;

	/** 体力を回復 */
	crapTrap.beRepaired(1);
	std::cout << "[ " << crapTrap << " ]" << std::endl;
	/** 体力を回復（境界値） */
	crapTrap.beRepaired(100);
	std::cout << "[ " << crapTrap << " ]" << std::endl;
	/** 体力を回復（境界値） */
	crapTrap.beRepaired(1);
	std::cout << "[ " << crapTrap << " ]" << std::endl;
	/** ダメージを受ける */
	crapTrap.takeDamage(99);
	std::cout << "[ " << crapTrap << " ]" << std::endl;
	/** 体力を回復 */
	crapTrap.beRepaired(10);
	std::cout << "[ " << crapTrap << " ]" << std::endl;
	/** 体力を回復（境界値）*/
	crapTrap.beRepaired(999);
	std::cout << "[ " << crapTrap << " ]" << std::endl;
	/** ダメージを受ける */
	crapTrap.takeDamage(99);
	std::cout << "[ " << crapTrap << " ]" << std::endl;
	/** ダメージを受ける */
	crapTrap.takeDamage(1);
	std::cout << "[ " << crapTrap << " ]" << std::endl;
	/** ダメージを受ける（死んでいる） */
	crapTrap.takeDamage(1);
	std::cout << "[ " << crapTrap << " ]" << std::endl;
	/** 攻撃する（死んでいる） */
	crapTrap.attack("Bad guy");
	std::cout << "[ " << crapTrap << " ]" << std::endl;
	/** 体力を回復（死んでいる） */
	crapTrap.beRepaired(10);
	std::cout << "[ " << crapTrap << " ]" << std::endl;

	return 0;
}
