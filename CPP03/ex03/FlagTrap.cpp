#include "FlagTrap.hpp"
#include "ClapTrap.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

FlagTrap::FlagTrap()
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	this->_isHighLevel = false;

	std::cout << "FlagTrap " << this->_name << " is born." << std::endl;
}

FlagTrap::FlagTrap(const std::string &name) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	this->_isHighLevel = false;

	std::cout << "FlagTrap " << this->_name << " is born." << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap &other)
{
	this->_name = other._name + "(copy)";
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDamage = other._attackDamage;
	this->_isHighLevel = false;
}

FlagTrap &FlagTrap::operator=(const FlagTrap &rhs)
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

FlagTrap::~FlagTrap()
{
	std::cout << "FlagTrap " << this->_name << " goes to sleep." << std::endl;
}

/** ハイタッチ */
void FlagTrap::highFiveGuys()
{
	if (this->_isHighLevel == true)
	{
		std::cout << YELLOW;
		std::cout << this->_name << " Already on the high-five mode.";
		std::cout << DEFAULT << std::endl;
		return;
	}
	this->_isHighLevel = true;
	std::cout << YELLOW;
	std::cout << this->_name << " Turn ON the high-five mode.";
	std::cout << DEFAULT << std::endl;
}

bool FlagTrap::getMode()const
{
	return this->_isHighLevel;
}

std::ostream &operator<<(std::ostream &os, const FlagTrap &flagTrap)
{
	os << "[ ";
	os << "Name:" << flagTrap.getName();
	os << " HP:" << flagTrap.getHitPoint();
	os << " EP:" << flagTrap.getEnergyPoint();
	os << " AD:" << flagTrap.getAttackDamage();
	os << " Mode: " << (flagTrap.getMode() ? "on" : "off");
	os << " ]";
	return os;
}
