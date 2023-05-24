#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
public:
	// Constructors
	MateriaSource();
	MateriaSource(const MateriaSource &other);

	// Destructor
	virtual ~MateriaSource();

	// Operators
	MateriaSource &operator=(const MateriaSource &rhs);

	// Member functions
	virtual void learnMateria(AMateria *materia);
	virtual AMateria *createMateria(std::string const &type);

	// Getters
	virtual AMateria *getInventory(int idx) const;

private:
	AMateria *_inventory[4];
};

std::ostream &operator<<(std::ostream &os, const IMateriaSource &MateriaSource);

#endif
