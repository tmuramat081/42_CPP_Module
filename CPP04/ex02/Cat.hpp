#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal
{
public:
	// Constructors
	Cat();

	// Destructor
	virtual ~Cat();

	// Copy constructor
	Cat(Cat &other);

	// Operator
	Cat operator=(const Cat &rhs);

	// Member functions
	virtual void makeSound() const;

	// Getters / setters
	virtual std::string getType() const;
	Brain *getBrain() const;

private:
	std::string type;
	Brain *_brain;
};

#endif
