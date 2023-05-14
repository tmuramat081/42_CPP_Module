#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(const std::string &name);
	ScavTrap();
	ScavTrap(const ScavTrap &other);
	ScavTrap operator=(const ScavTrap &other);
	~ScavTrap();
	void guardGate();

private:
	bool _isGateKeeperMode;
};

std::ostream &operator<<(std::ostream &os, const ScavTrap &scavTrap);

#endif
