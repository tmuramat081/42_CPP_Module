#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	// Contructors
	ScavTrap(const std::string &name);
	ScavTrap();

	// Copy constructor
	ScavTrap(const ScavTrap &other);

	// Operator
	ScavTrap operator=(const ScavTrap &other);

	// Destructor
	~ScavTrap();

	// Member functions
	void guardGate();
	bool getMode() const;

private:
	bool _isGateKeeperMode;
};

std::ostream &operator<<(std::ostream &os, const ScavTrap &scavTrap);

#endif
