#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	// Constructors
	Character(const std::string &name);
	Character();
	Character(const Character &other);

	// Destructor
	~Character();

	// Operators
	Character &operator=(const Character &rhs);

	// Member functions
	void equip(AMateria *materia);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

	// Getters / Setters
	std::string const &getName() const;
	AMateria const * getInventory(int idx) const;

private:
	std::string _name;
	AMateria *_inventory[4];
};

std::ostream &operator<<(std::ostream &os, const ICharacter &character);

#endif
