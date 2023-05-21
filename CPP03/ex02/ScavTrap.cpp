#include "ScavTrap.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "default";
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
		std::cout << this->_name << " Turn OFF the gate keeper mode.";
		std::cout << DEFAULT << std::endl;
	}
	else
	{
		this->_isGateKeeperMode = true;
		std::cout << YELLOW;
		std::cout << this->_name << " Turn ON the gate keeper mode.";
		std::cout << DEFAULT << std::endl;
	}
}

bool ScavTrap::getMode() const
{
	return this->_isGateKeeperMode;
}

std::ostream &operator<<(std::ostream &os, const ScavTrap &scavTrap)
{
	os << "[ ";
 	os << "Name:" << scavTrap.getName();
	os << " HP:" << scavTrap.getHitPoint();
	os << " EP:" << scavTrap.getEnergyPoint();
	os << " AD:" << scavTrap.getAttackDamage();
	os << " Mode:" << (scavTrap.getMode() ? "on" : "off");
	os << " ]";
	return os;
}
