#include "ScavTrap.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "John Doe";
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	_isGateKeeperMode = false;
	std::cout << "ScavTrap " << this->_name << " is born." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	_isGateKeeperMode = false;
	std::cout << "ScavTrap " << this->_name << " is born." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDamage = other._attackDamage;
	this->_isGateKeeperMode = other._isGateKeeperMode;
}

ScavTrap ScavTrap::operator=(const ScavTrap &other)
{
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDamage = other._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " goes to sleep." << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->_isGateKeeperMode == true)
	{
		this->_isGateKeeperMode = false;
		std::cout << YELLOW;
		std::cout << "ScavTrap " << this->_name << " switchs to normal mode." << std::cout << DEFAULT << std::endl;
	}
	std::cout << YELLOW;
	std::cout << "ScavTrap " << this->_name << " switchs to gate keeper mode.";
	std::cout << DEFAULT << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ScavTrap &scavTrap)
{

	os << scavTrap.getName() << " HP:" << scavTrap.getHitPoint() << " EP:" << scavTrap.getEnergyPoint() << " AD:" << scavTrap.getAttackDamage() << "MODE" << scavTrap.getCurrentMode();
	return os;
}
