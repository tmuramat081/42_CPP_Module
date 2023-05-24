#ifndef FIRE_HPP
#define FIRE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Fire : public AMateria
{
public:
	// Constructors
	Fire();
	Fire(const Fire &other);

	// Destructor
	virtual ~Fire();

	// Operator
	Fire &operator=(const Fire &assign);

	// Member functions
	virtual Fire *clone() const;
	virtual void use(ICharacter &target);
};

#endif
