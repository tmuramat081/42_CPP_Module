#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
	ClapTrap(const std::string &name);
	ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap operator=(const ClapTrap &other);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName() const;
	unsigned int getHitPoint() const;
	unsigned int getEnergyPoint() const;
	unsigned int getAttackDamage() const;

protected:
	static const unsigned int HP_MAX = 100;

	bool isDied();
	bool isStarved();
	std::string _name;
	unsigned int _hitPoint;
	unsigned int _energyPoint;
	unsigned int _attackDamage;
};

std::ostream &operator<<(std::ostream &os, const ClapTrap &clapTrap);

#endif
