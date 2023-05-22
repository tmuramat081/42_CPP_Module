#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
	return this->_type;
}

void use(ICharacter& target)
{
	(void)target;
	return ;
}
