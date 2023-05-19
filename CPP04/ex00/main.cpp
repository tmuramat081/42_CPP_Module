#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal *meta = new Animal();
	const Animal *c = new Cat();
	const Animal *d = new Dog();

	std::cout << "Type: " << meta->getType() << " " << std::endl;
	std::cout << "Type: " << c->getType() << " " << std::endl;
	std::cout << "Type: " << d->getType() << " " << std::endl;

	c->makeSound();
	d->makeSound();
	meta->makeSound();

	delete meta;
	delete c;
	delete d;

	const WrongAnimal *wmeta = new WrongAnimal();
	const WrongAnimal *wi = new WrongCat();

	wmeta->makeSound();
	wi->makeSound();

	delete wmeta;
	delete wi;

	return 0;
}
