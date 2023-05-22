#include "Character.hpp"

// Constructors
Character::Character(const std::string &name) : _name(name) {}

Character::Character(const Character &other)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = other._inventory[i];
	}
}

// Destructor
Character::~Character() {}

// Operators
Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			// delete this->_inventory[i];
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
			this->_inventory[i] = materia;
			return;
		}
	}
	std::cout << "Inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	this->_inventory[idx]->use(target);
}

std::string const &Character::getName() const
{
	return this->_name;
}
