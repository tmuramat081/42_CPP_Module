#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal()
{
	this->type = "N/A";
	std::cout << "\033[0;33mDefault Constructor called of WrongAnimal\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	this->type = copy.type;
	std::cout << "\033[0;33mCopy Constructor called of WrongAnimal\033[0m" << std::endl;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[0;33mDestructor called of WrongAnimal\033[0m" << std::endl;
}

// Member functions
void WrongAnimal::makeSound() const
{
	std::cout << "<< WrongAnimal" << std::endl;
}

// Operators
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assign)
{
	if (this != &assign)
	{
		this->type = assign.type;
	}
	return *this;
}

// Getters / Setters
std::string WrongAnimal::getType() const
{
	return this->type;
}
