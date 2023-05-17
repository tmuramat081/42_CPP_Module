#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name);
void randomChump(std::string name);
Zombie *zombieHorde(int N, std::string name);

int main()
{
	Zombie *zombies;

	try
	{
		zombies = zombieHorde(10, "Leatherface");
		for (int i = 0; i < 10; ++i)
		{
			zombies[i].announce();
		}
		delete[] zombies;
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cerr << "invalid argument: " << e.what() << std::endl;
	}
	return 0;
}
