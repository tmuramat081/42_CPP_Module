#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->_investory[i] = NULL;
	}
}

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
	for (int i = 0; i < 4; i++)
	{
		delete this->_investory[i];
	}
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
			std::cout << "leean materia " << materia->getType() << std::endl;
			this->_investory[i] = materia->clone();
			return ;
		}
	}
	std::cout << "Investory is full!" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_investory[i] && _investory[i]->getType() == type)
		{
			std::cout << "create materia of " << _investory[i]->getType() << std::endl;
			return this->_investory[i]->clone();
		}
	}
	std::cout << "invalid type" << std::endl;
	return NULL;
}

AMateria *MateriaSource::getInvestory(int idx) const
{
	return this->_investory[idx];
}

std::ostream &operator<<(std::ostream &os, const IMateriaSource &materiaSource)
{
	os << "== Available materias ==" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		os << "No." << i << " ";
		if (materiaSource.getInvestory(i))
		{
			os << materiaSource.getInvestory(i)->getType();
		}
		else
		{
			os << "NONE";
		}
		os << std::endl;
	}

	os << "========================";
	return os;
}
