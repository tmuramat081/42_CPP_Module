#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
public:
	Cat();
	virtual ~Cat();
	Cat(Cat &other);
	Cat operator=(const Cat &rhs);
	virtual void makeSound()const;
	virtual std::string getType()const;

private:
	std::string type;
};

#endif
