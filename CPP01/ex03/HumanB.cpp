#include "HumanB.hpp"
#include <iostream>

void HumanB::attack(void)
{
	std::cout << this->name << "atack with their";
	std::cout << this->wepon->type << std::endl;
}