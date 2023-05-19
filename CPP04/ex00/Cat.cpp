#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat's constructor is called." << std::endl;
}

Cat::~Cat()
{
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
	this->type = rhs.type;
	return *this;
}

std::string Cat::getType()const
{
	return this->type;
}

void Cat::makeSound()const
{
	std::cout << BLUE;
	std::cout << "(^._.^) < \"Nyan Nyan!\"";
	std::cout << DEFAULT << std::endl;
}
