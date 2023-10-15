#include "DiamondTrap.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name), ScavTrap(name), FlagTrap(name), _name(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap " << this->_name << " is born." << std::endl;
}

DiamondTrap::DiamondTrap() : ClapTrap(), _name("default")
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap " << this->_name << " is born." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDamage = other._attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " goes to sleep." << std::endl;

}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << YELLOW;
	std::cout << "I am " << this->_name << ", inherited of " << ClapTrap::_name << ".";
	std::cout << DEFAULT << std::endl;
	// std::cout << "Address: " << this << std::endl;
}

std::string DiamondTrap::getName() const
{
	return this->_name;
}

std::ostream &operator<<(std::ostream &os, const DiamondTrap &diamondTrap)
{

	os << "[ ";
	os << "Name:" << diamondTrap.getName();
	os << " HP:" << diamondTrap.getHitPoint();
	os << " EP:" << diamondTrap.getEnergyPoint();
	os << " AD:" << diamondTrap.getAttackDamage();
	os << " ]";
	return os;
}
