#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice: public AMateria
{
public:
	// Constructors
	Ice();
	Ice(const Ice &other);

	// Destructor
	~Ice();

	// Operators
	Ice &operator=(const Ice &rhs);

	Ice *clone() const;
	void use(ICharacter &target);
};

#endif
