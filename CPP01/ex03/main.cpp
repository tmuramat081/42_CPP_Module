#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

#define GREEN "\033[0;92m"
#define DEFAULT "\033[0;39m"

int main()
{
	std::cout << GREEN << "-- Test HumanA --" << DEFAULT << std::endl;
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << GREEN << "-- Test HumanB --" << DEFAULT << std::endl;
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
