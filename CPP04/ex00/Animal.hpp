#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

#include <iostream>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	Animal(Animal &other);
	Animal operator=(const Animal &rhs);
	virtual void makeSound()const;
	virtual std::string getType() const;

protected:
	std::string type;
};

#endif
