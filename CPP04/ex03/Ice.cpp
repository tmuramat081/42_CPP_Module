#include "Ice.hpp"

// Constructors
Ice::Ice()
{
	_clone() = 0;
	std::cout << "\e[0;33mDefault Constructor called of Ice\e[0m" << std::endl;
}

Ice::Ice(const Ice &copy)
{
	_clone() = copy.getClone()();
	std::cout << "\e[0;33mCopy Constructor called of Ice\e[0m" << std::endl;
}

Ice::Ice(void clone())
{
	_clone() = clone();
	std::cout << "\e[0;33mFields Constructor called of Ice\e[0m" << std::endl;
}


// Destructor
Ice::~Ice()
{
	std::cout << "\e[0;31mDestructor called of Ice\e[0m" << std::endl;
}


// Operators
Ice & Ice::operator=(const Ice &assign)
{
	_clone() = assign.getClone()();
	return *this;
}


// Getters / Setters
void Ice::getClone()() const
{
	return _clone();
}
