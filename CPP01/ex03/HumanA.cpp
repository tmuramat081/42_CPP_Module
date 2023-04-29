#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(){

}

void HumanA::attack(void)
{
	std::cout << this->name << "atack with their";
	std::cout << this->wepon->type << std::endl;
}