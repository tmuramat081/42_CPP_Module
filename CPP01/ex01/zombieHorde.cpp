#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name);

Zombie *zombieHorde(int N, std::string name)
{
	Zombie
	if (N <= 0)
	{
		return NULL;
	}
	try
	{
		Zombie *zombies = new Zombie[N];

		for (int i = 0; i < N; i++)
		{
			zombies[i] = Zombie(name + "_" + std::to_string(i));
		}
	}
	catch(std::bad_alloc &e)
	{
		std::cerr << "Memory: allocation failed.: " << e.what() << std::endl;
	}
	return zombies;
}
