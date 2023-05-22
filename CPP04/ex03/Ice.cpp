#include "Ice.hpp"

// Constructors
Ice::Ice() : AMateria("cure") {}

Ice::Ice(const Ice &other) {
	(void)other;
}

// Destructor
Ice::~Ice() {}

// Operators
Ice &Ice::operator=(const Ice &rhs)
{
	(void)rhs;
	return *this;
}

Ice *Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoot an ice bolt at " << target.getName();
}
