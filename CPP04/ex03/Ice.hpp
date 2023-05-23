#ifndef ICE_HPP
#define ICE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Ice: public AMateria
{
public:
	// Constructors
	Ice();
	Ice(const Ice &other);

	// Destructor
	virtual ~Ice();

	// Operators
	Ice &operator=(const Ice &rhs);

	// Member functions
	virtual Ice *clone() const;
	virtual void use(ICharacter &target);
};

#endif
