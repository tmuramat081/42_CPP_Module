#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name)
{
	Zombie *z = new Zombie(name);
	return z;
}
