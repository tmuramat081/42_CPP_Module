#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	// Constructors
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);

	// Destructor
	~WrongAnimal();

	// Operators
	WrongAnimal &operator=(const WrongAnimal &assign);

	// Member functions
	void makeSound() const;

	// Getters / Setters
	std::string getType() const;

private:
	std::string type;
};

#endif
