#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	this->type = "N/A";
	std::cout << "AAnimal's constructor is called." << std::endl;
}

AAnimal::AAnimal(AAnimal &other)
{
	this->type = other.type;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal's destructor is called." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

void AAnimal::makeSound()const
{
	std::cout << RED;
	std::cout << "[ AAnimal does not make sound. ]";
	std::cout << DEFAULT << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}

