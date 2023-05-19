#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
public:
	// Constructors
	WrongCat();
	WrongCat(const WrongCat &copy);

	// Destructor
	~WrongCat();

	// Operators
	WrongCat &operator=(const WrongCat &assign);

	// Member functions
	void makeSound()const;

	// Getters / Setters
	std::string getName() const;

private:
	std::string name;
};

#endif
