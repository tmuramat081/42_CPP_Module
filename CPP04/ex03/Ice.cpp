#include "Ice.hpp"

// Constructors
Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) {
	*this = other;
}

// Destructor
Ice::~Ice() {}

// Operators
Ice &Ice::operator=(const Ice &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

Ice *Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout << "\033[0;32m* shoot an ice bolt at " << target.getName() << " *\033[0m" << std::endl;
}
