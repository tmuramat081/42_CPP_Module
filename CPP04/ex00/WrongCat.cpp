#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat()
{
	this->name = "Wrong cat";
	std::cout << "\033[0;33mDefault Constructor called of WrongCat\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	this->name = copy.name;
	std::cout << "\033[0;33mCopy Constructor called of WrongCat\033[0m" << std::endl;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "\033[0;33mDestructor called of WrongCat\033[0m" << std::endl;
}

void WrongCat::makeSound()const
{
	std::cout << "WrongCat" << std::endl;
}

// Operators
WrongCat &WrongCat::operator=(const WrongCat &assign)
{
	this->name = assign.name;
	return *this;
}

// Getters / Setters
std::string WrongCat::getName() const
{
	return this->name;
}
