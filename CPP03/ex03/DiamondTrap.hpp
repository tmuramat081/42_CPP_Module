#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FlagTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

class DiamondTrap : public ScavTrap, public FlagTrap
{
public:
	// Constructors
	DiamondTrap(const std::string &name);
	DiamondTrap();

	// Copy constructor
	DiamondTrap(const DiamondTrap &other);

	// Operator
	DiamondTrap &operator=(const DiamondTrap &rhs);

	// Destructor
	~DiamondTrap();

	// Member functions
	void attack(const std::string &target);
	void whoAmI();
	std::string getName() const;

	// Getters / setters
	// std::string getName()const;
	// unsigned int getHitPoint()const;
	// unsigned int getEnergyPoint()const;
	// unsigned int getAttackDamage()const;
	// std::string getTrueName()const;

private:
	std::string _name;
};

std::ostream &operator<<(std::ostream &os, const DiamondTrap &flagTrap);

#endif
