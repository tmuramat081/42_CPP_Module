#include "Cure.hpp"

// Constructors
Cure::Cure() : AMateria("cure") {}

// Copy constructor
Cure::Cure(const Cure &other)
{
	*this = other;
}

// Destructor
Cure::~Cure()
{

}

// Operators
Cure &Cure::operator=(const Cure &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

Cure *Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName();
	std::cout << "'s wounds *" << std::endl;
}
