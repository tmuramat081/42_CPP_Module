#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), ScavTrap(name), FlagTrap(name), _name(name)
{
	this->ScavTrap::ClapTrap::_energyPoint =
}

DiamondTrap::DiamondTrap(){}



void DiamondTrap::whoAmI(){}

std::ostream &operator<<(std::ostream &os, const DiamondTrap &diamondTrap)
{

}