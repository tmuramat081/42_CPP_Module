#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon()
{
	std::cout << "Weapon's default constructor is called." << std::endl;
};

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "Weapon's constructor is called." << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon's destructor is called." << std::endl;
};

std::string const &Weapon::getType() const
{
	return this->_type;
}

void Weapon::setType(const std::string type)
{
	this->_type = type;
}
