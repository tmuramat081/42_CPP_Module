#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string const &name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA's constructor is called." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA's destructor is called." << std::endl;
}

void HumanA::attack(void)
{
	std::cout << this->_name << " atack with their ";
	std::cout << this->_weapon.getType() << std::endl;
}