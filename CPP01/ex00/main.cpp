#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	/** ヒープ領域を用いた確保 */
	try
	{
		Zombie *z = newZombie("Heap zombie");
		z->announce();
		delete z;
	}
	catch(std::bad_alloc &e)
	{
		std::cerr << "Memory: allocation failed.: " << e.what() << std::endl;
	}

	/** スタック領域を用いた確保 */
	randomChump("Stack zombie");

	return 0;
}
