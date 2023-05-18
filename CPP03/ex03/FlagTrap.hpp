#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : virtual public ClapTrap
{
public:
	FlagTrap(const std::string &name);
	FlagTrap();
	FlagTrap(const FlagTrap &other);
	FlagTrap operator=(const FlagTrap &other);
	~FlagTrap();
	void highFiveGuys();

private:
	bool _isHighMode;
};

std::ostream &operator<<(std::ostream &os, const FlagTrap &flagTrap);

#endif
