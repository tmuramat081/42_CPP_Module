#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name);

Zombie *zombieHorde(int N, std::string name)
{
	if (N < 0)
	{
		throw std::invalid_argument("N must be positive");
	}

	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
	}

	return zombies;
}
