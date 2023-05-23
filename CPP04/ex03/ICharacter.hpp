#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;

class ICharacter
{
public:
	// Destructor
	virtual ~ICharacter() {}

	// Member functions
	virtual void equip(AMateria *materia) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;

	// Getters
	virtual std::string const &getName() const = 0;
	virtual AMateria const * getInvestory(int idx) const = 0;
};

#endif
