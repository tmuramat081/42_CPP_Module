#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Animal::Animal()
{
	this->type = "N/A";
	this->_brain = new Brain;
	std::cout << "Animal's constructor is called." << std::endl;
}

Animal::Animal(Animal &other)
{
	this->type = other.type;
	this->_brain = other._brain;
}

Animal::~Animal()
{
	delete this->_brain;
	std::cout << "Animal's destructor is called." << std::endl;
}

Animal Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->_brain = rhs._brain;
	}
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

Brain *Animal::getBrain()const
{
	return this->_brain;
}
