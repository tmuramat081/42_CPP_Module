#include "Fire.hpp"

// Constructors
Fire::Fire() : AMateria("fire") {}

// Copy constructor
Fire::Fire(const Fire &other)
{
	*this = other;
}

// Destructor
Fire::~Fire(){}

// Operators
Fire &Fire::operator=(const Fire &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

Fire *Fire::clone() const
{
	return new Fire();
}

void Fire::use(ICharacter &target)
{
	std::cout << "\033[0;32m* ignite a blazing inferno to " << target.getName() << " *\033[0m" << std::endl;
}
