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
	~MateriaSource();

	// Operators
	MateriaSource &operator=(const MateriaSource &rhs);

	// Member functions
	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);

private:
	AMateria *_investory[4];
};

#endif
