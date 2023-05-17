#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << "HumanA's constructor is called." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB's destructor is called." << std::endl;
}

void HumanB::attack(void)
{
	std::cout << this->_name << " atack with their ";
	std::cout << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
