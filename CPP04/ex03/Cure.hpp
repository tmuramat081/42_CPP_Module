#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	// Constructors
	Cure();
	Cure(const Cure &other);

	// Destructor
	~Cure();

	// Operators
	Cure &operator=(const Cure &assign);

	// Getters / Setters
	Cure *clone() const;

	void use(ICharacter &target);

};

#endif
