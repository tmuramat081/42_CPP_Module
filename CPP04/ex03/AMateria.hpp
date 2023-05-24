#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;
class AMateria
{
public:
	// Constructor
	AMateria(std::string const &type);
	AMateria();

	// Copy constructor
	AMateria(const AMateria &other);

	// Destructor
	virtual ~AMateria();

	AMateria &operator=(const AMateria &rhs);

	// Member functions
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);

	// Getters / setters
	std::string const &getType() const;

protected:
	std::string _type;
};

#endif
