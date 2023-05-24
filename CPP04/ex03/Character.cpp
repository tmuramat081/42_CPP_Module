#include "Character.hpp"

// Constructors
Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::Character(const Character &other)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = other._inventory[i];
	}
}

// Destructor
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
	}
}

// Operators
Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
			}
			this->_inventory[i] = _inventory[i]->clone();
		}
	}
	return *this;
}

void Character::equip(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			std::cout << "\033[0;34mNew equipment: " << materia->getType() << "\033[0m" << std::endl;
			this->_inventory[i] = materia;
			return;
		}
	}
	std::cout << "Inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || 3 < idx)
	{
		std::cerr << "\033[0;31mError: invalid index.\033[0m" << std::endl;
		return;
	}
	std::cout << "\033[0;34mDelete equipment: " << this->_inventory[idx]->getType() << "\033[0m" << std::endl;
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || 3 < idx)
	{
		std::cerr << "\033[0;31mError: invalid index.\033[0m" << std::endl;
		return;
	}
	else if (!this->_inventory[idx])
	{
		std::cerr << "\033[0;31mError: no equipment.\033[0m" << std::endl;
		return;
	}
	this->_inventory[idx]->use(target);
}

std::string const &Character::getName() const
{
	return this->_name;
}

AMateria const *Character::getInventory(int idx) const
{
	return this->_inventory[idx];
}

std::ostream &operator<<(std::ostream &os, const ICharacter &character)
{
	os << "== " << character.getName() << "'s materias ==" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		os << "No." << i << " ";
		if (character.getInventory(i))
		{
			os << character.getInventory(i)->getType();
		}
		else
		{
			os << "(none)";
		}
		os << std::endl;
	}
	os << "======================";
	return os;
}
