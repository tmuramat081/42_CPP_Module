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
	std::cout << "* shoot an ice bolt at " << target.getName() << " *" << std::endl;
}
