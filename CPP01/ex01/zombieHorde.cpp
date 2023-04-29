#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name);

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombies[i] = Zombie(name);
	}
	return zombies;
}