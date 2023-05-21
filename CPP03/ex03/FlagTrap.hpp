#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : virtual public ClapTrap
{
public:
	// Constructor
	FlagTrap(const std::string &name);
	FlagTrap();

	// Copy constructor
	FlagTrap(const FlagTrap &other);

	// Operator
	FlagTrap &operator=(const FlagTrap &other);

	// Destructor
	~FlagTrap();

	// Member functions
	void highFiveGuys();

	// Getters / setters
	bool getMode()const;

private:
	bool _isHighLevel;
};

std::ostream &operator<<(std::ostream &os, const FlagTrap &flagTrap);

#endif
