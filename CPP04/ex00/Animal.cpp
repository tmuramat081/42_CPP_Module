#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	this->type = "N/A";
	std::cout << "Animal's constructor is called." << std::endl;
}

Animal::Animal(Animal &other)
{
	if (this == &other)
	{
		return;
	}
	this->type = other.type;
}

Animal Animal::operator=(const Animal &rhs)
{
	this->type = rhs.type;
	return *this;
}

void Animal::makeSound()const
{
	std::cout << RED;
	std::cout << "[ Animal does not make sound. ]";
	std::cout << DEFAULT << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

Animal::~Animal()
{
	std::cout << "Animal's destructor is called." << std::endl;
}
