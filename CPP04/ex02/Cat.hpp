#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal
{
public:
	Cat();
	virtual ~Cat();
	Cat(Cat &other);
	Cat operator=(const Cat &rhs);
	virtual void makeSound() const;
	virtual std::string getType() const;
	Brain *getBrain() const;

private:
	std::string type;
	Brain *_brain;
};

#endif
