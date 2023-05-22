#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource(){}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		this->_investory[i] = other._investory[i];
	}
}

// Destructor
MateriaSource::~MateriaSource()
{
}


// Operators
MateriaSource & MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			this->_investory[i] = rhs._investory[i];
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_investory[i] == NULL)
		{
			this->_investory[i] = materia;
		}
	}
	std::cout << "Inventory is full!" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_investory[i]->getType() == type)
		{
			return this->_investory[i]->clone();
		}
	}
	return NULL;
}
