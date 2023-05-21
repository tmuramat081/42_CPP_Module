#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
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
	Brain *getBrain()const;

private:
	std::string type;
	Brain *_brain;
};

#endif
