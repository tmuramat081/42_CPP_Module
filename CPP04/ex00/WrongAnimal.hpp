#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	// Constructors
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);

	// Destructor
	virtual ~WrongAnimal();

	// Operators
	WrongAnimal &operator=(const WrongAnimal &assign);

	// Member functions
	virtual void makeSound() const;

	// Getters / Setters
	std::string getType() const;

private:
	std::string type;
};

#endif
