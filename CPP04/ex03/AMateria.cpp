#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(){}

AMateria::AMateria(const AMateria &other)
{
	this->_type = other._type;
}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}

void AMateria::use(ICharacter& target)
{
std::cout << "* do nothing to " << target.getName() << " *" << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->_type;
}
