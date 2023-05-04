#include <iostream>
#include "Controller.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

int main()
{
	Controller controller;
	std::string line;

	std::cout << BLUE;
	std::cout << ">> PhoneBook APP";
	std::cout << DEFAULT << std::endl;

	while(42)
	{
		std::getline(std::cin, line);
		controller.route(line);
	}
}