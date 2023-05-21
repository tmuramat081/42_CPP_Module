#include "Cure.hpp"

// Constructors
Cure::Cure()
{
	_clone() = 0;
	std::cout << "\e[0;33mDefault Constructor called of Cure\e[0m" << std::endl;
}

Cure::Cure(const Cure &copy)
{
	_clone() = copy.getClone()();
	std::cout << "\e[0;33mCopy Constructor called of Cure\e[0m" << std::endl;
}

Cure::Cure(void clone())
{
	_clone() = clone();
	std::cout << "\e[0;33mFields Constructor called of Cure\e[0m" << std::endl;
}


// Destructor
Cure::~Cure()
{
	std::cout << "\e[0;31mDestructor called of Cure\e[0m" << std::endl;
}


// Operators
Cure & Cure::operator=(const Cure &assign)
{
	_clone() = assign.getClone()();
	return *this;
}


// Getters / Setters
void Cure::getClone()() const
{
	return _clone();
}
