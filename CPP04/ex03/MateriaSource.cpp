#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = other._inventory[i];
	}
}

// Destructor
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
}

// Operators
MateriaSource & MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
			}
			this->_inventory[i] = rhs._inventory[i];
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			std::cout << "\033[0;33mLearn materia: " << materia->getType() << "\033[0m" << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full!" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] && _inventory[i]->getType() == type)
		{
			std::cout << "\033[0;33mCreate materia: " << _inventory[i]->getType() << "\033[0m" << std::endl;
			return this->_inventory[i]->clone();
		}
	}
	std::cerr << "Error: invalid type." << std::endl;
	return NULL;
}

AMateria *MateriaSource::getInventory(int idx) const
{
	return this->_inventory[idx];
}

std::ostream &operator<<(std::ostream &os, const IMateriaSource &materiaSource)
{
	os << "== Available materias ==" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		os << "No." << i << " ";
		if (materiaSource.getInventory(i))
		{
			os << materiaSource.getInventory(i)->getType();
		}
		else
		{
			os << "(none)";
		}
		os << std::endl;
	}

	os << "========================";
	return os;
}
