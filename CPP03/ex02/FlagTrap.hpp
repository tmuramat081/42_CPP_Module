#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap
{
public:
	FlagTrap(const std::string &name);
	FlagTrap();
	FlagTrap(const FlagTrap &other);
	FlagTrap operator=(const FlagTrap &other);
	~FlagTrap();
	void highFiveGuys();
	bool getMode()const;

private:
	bool _isHighLevel;
};

std::ostream &operator<<(std::ostream &os, const FlagTrap &flagTrap);

#endif
