#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal(std::string &name);
	Animal();
	Animal(Animal &other);
	void makeSound();

protected:
	std::string type;
};

#endif

