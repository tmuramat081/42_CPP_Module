#ifndef AAnimal_HPP
#define AAnimal_HPP

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

#include "Brain.hpp"
#include <iostream>

class AAnimal
{
public:
	// Constructors
	AAnimal();

	// Copy constructor
	AAnimal(AAnimal &other);

	// Destructor
	virtual ~AAnimal();

	// Operator
	AAnimal &operator=(const AAnimal &rhs);

	// Member functions
	virtual void makeSound() const = 0;

	// Getters / setters
	virtual std::string getType() const = 0;

protected:
	std::string type;
};

#endif
