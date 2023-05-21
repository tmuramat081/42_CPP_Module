#include "Dog.hpp"

Dog::Dog()
{
	this->_brain = new Brain;
	this->type = "Dog";
	std::cout << "Dog's constructor is called." << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog's destructor is called." << std::endl;
}

Dog::Dog(Dog &other)
{
	this->_brain = new Brain(*other._brain);
	this->type = other.type;
}

Dog Dog::operator=(const Dog &rhs)
{
	this->type = rhs.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << GREEN;
	std::cout << " /^ ^\\ < \"Wan Wan!\"";
	std::cout << DEFAULT << std::endl;
}

std::string Dog::getType() const
{
	return this->type;
}

Brain *Dog::getBrain()const
{
	return this->_brain;
}
