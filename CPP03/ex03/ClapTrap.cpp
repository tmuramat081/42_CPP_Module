#include "ClapTrap.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

ClapTrap::ClapTrap() : _name("default"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " is born." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " is born." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDamage = other._attackDamage;
}

ClapTrap ClapTrap::operator=(const ClapTrap &rhs)
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

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " goes to sleep." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	/** HPが0の場合は何もしない */
	if (isDied())
	{
		std::cout << RED;
		std::cout << "Already dead.";
		std::cout << DEFAULT << std::endl;
		return;
	}
	/** EPが0の場合は何もしない */
	if (this->isStarved())
	{
		std::cout << RED;
		std::cout << "Not enough energy points.";
		std::cout << DEFAULT << std::endl;
		return;
	}

	/** EPを1消費し、相手を攻撃する */
	this->_energyPoint -= 1;

	std::cout << GREEN;
	std::cout << this->getName() << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!";
	std::cout << DEFAULT << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	/** HPが0の場合は何もしない */
	if (isDied())
	{
		std::cout << RED;
		std::cout << "Already dead.";
		std::cout << DEFAULT << std::endl;
		return;
	}

	if (this->_hitPoint < amount)
	{
		amount -= amount - this->_hitPoint;
	}
	this->_hitPoint -= amount;

	std::cout << RED;
	std::cout << this->getName() << " has taken " << amount << " points of damage!";
	std::cout << DEFAULT << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	/** HPが0の場合は何もしない */
	if (isDied())
	{
		std::cout << RED;
		std::cout << "Already dead.";
		std::cout << DEFAULT << std::endl;
		return;
	}
	/** EPが0の場合は何もしない */
	if (isStarved())
	{
		std::cout << RED;
		std::cout << "Not enough energy points.";
		std::cout << DEFAULT << std::endl;
		return;
	}

	/** EPを1消費し、HPを回復する */
	this->_energyPoint -= 1;
	if (this->_hitPoint + amount > ClapTrap::HP_MAX)
	{
		amount = ClapTrap::HP_MAX - this->_hitPoint;
	}
	this->_hitPoint += amount;

	std::cout << BLUE;
	std::cout << this->getName() << " has repaired " << amount << " points of hit points!";
	std::cout << DEFAULT << std::endl;
}

/** 死亡状態か判定する */
bool ClapTrap::isDied()
{
	return this->_hitPoint == 0;
}

/**　枯渇状態か判定する */
bool ClapTrap::isStarved()
{
	return this->_energyPoint == 0;
}

std::string ClapTrap::getName() const
{
	return this->_name;
}

unsigned int ClapTrap::getHitPoint() const
{
	return this->_hitPoint;
}

unsigned int ClapTrap::getEnergyPoint() const
{
	return this->_energyPoint;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

std::ostream &operator<<(std::ostream &os, const ClapTrap &clapTrap)
{
	os << "[ ";
	os << "Name:" << clapTrap.getName();
	os << " HP:" << clapTrap.getHitPoint();
	os  << " EP:" << clapTrap.getEnergyPoint();
	os << " AD:" << clapTrap.getAttackDamage();
	os << " ]";
	return os;
}
