#include <iostream>

#define GREEN "\033[0;92m"
#define DEFAULT "\033[0;39m"

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << GREEN << "-- Check Addresses --" << DEFAULT << std::endl;
	std::cout << "string: " << &string << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << GREEN << "-- Check Values --" << DEFAULT << std::endl;
	std::cout << "string: " << string << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;

	return 0;
}
