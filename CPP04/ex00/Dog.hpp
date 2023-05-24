#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
public:
	Dog();
	virtual ~Dog();
	Dog(Dog &other);
	Dog operator=(const Dog &rhs);
	virtual void makeSound() const;
	virtual std::string getType() const;

private:
	std::string type;
};

#endif
