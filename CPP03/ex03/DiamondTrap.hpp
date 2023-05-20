#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FlagTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

class DiamondTrap: public ScavTrap, public FlagTrap
{
public:
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();
	void whoAmI();
	void attack();

private:
	std::string _name;
};

std::ostream &operator<<(std::ostream &os, const DiamondTrap &flagTrap);

#endif
