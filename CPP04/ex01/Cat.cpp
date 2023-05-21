#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->_brain = new Brain;
	std::cout << "Cat's constructor is called." << std::endl;
}

Cat::Cat(Cat &other)
{
	this->_brain = other._brain;
	this->type = other.type;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat's destructor is called." << std::endl;
}

Cat Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		this->_brain = rhs._brain;
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

Brain *Cat::getBrain()const
{
	return this->_brain;
}
