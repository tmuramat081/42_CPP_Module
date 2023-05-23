#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
{
public:
	// Constructors
	Dog();

	// Copy constructor
	Dog(Dog &other);

	// Destructor
	virtual ~Dog();

	// Operators
	Dog operator=(const Dog &rhs);

	// Member functions
	virtual void makeSound() const;

	// Getters / setters
	virtual std::string getType() const;
	Brain *getBrain()const;

private:
	std::string type;
	Brain *_brain;
};

#endif
