#include "Cat.hpp"

Cat::Cat()
{
	this->_brain = new Brain;
	this->type = "Cat";
	std::cout << "Cat's constructor is called." << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat's destructor is called." << std::endl;
}

Cat::Cat(Cat &other)
{
	if (this == &other) {
		return ;
	}
	this->type = other.type;
}

Cat Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

void Cat::makeSound()const
{
	std::cout << BLUE;
	std::cout << "(^._.^) < \"Nyan Nyan!\"";
	std::cout << DEFAULT << std::endl;
}

std::string Cat::getType()const
{
	return this->type;
}

