#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie z1("Stack zombie");
	z1.announce();

	Zombie *z2 = new Zombie("Heap zombie");
	z2->announce();

	randomChump("Freddy");

	delete z2;
}
