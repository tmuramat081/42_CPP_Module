#ifndef CURE_HPP
#define CURE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Cure : public AMateria
{
public:
	// Constructors
	Cure();
	Cure(const Cure &other);

	// Destructor
	virtual ~Cure();

	// Operators
	Cure &operator=(const Cure &assign);

	// Member functions
	virtual Cure *clone() const;
	virtual void use(ICharacter &target);
};

#endif
