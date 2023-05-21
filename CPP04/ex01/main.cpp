#include <cstdlib>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Constant.hpp"

#define DEFAULT "\033[0;39m"
#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define RED "\033[0;91m"

void putIdeas(const Brain *brain)
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << brain->getIdea(i) << std::endl;
	}
}

void putIdeaByRandom(const Brain *brain)
{
	srand(static_cast<unsigned int>(time(0)));
	int index = rand() % 100;

	std::cout << GREEN;
	std::cout << "Pick up a next idea: ";
	std::cout << brain->getIdea(index);
	std::cout << DEFAULT << std::endl;
}

void setIdeas(Brain *brain, const std::string ideas[100])
{
	for (int index = 0; index < 100; index++)
	{
		brain->setIdea(index, ideas[index]);
	}
}

int main()
{
	const Dog *dog = new Dog();
	Cat *cat = new Cat();
	const Cat *copy_cat = new Cat(*cat);

	Brain *cat_brain = cat->getBrain();
	Brain *copy_cat_brain = copy_cat->getBrain();

	setIdeas(cat_brain, fantasticIdeas);

	putIdeas(cat_brain);

	putIdeaByRandom(cat_brain);
	putIdeaByRandom(copy_cat_brain);

	delete dog;
	delete cat;
	delete copy_cat;

	return 0;
}

#ifdef LEAK_CHECK
__attribute__((destructor))
void end(void)
{
	system("leaks -q a.out");
}
#endif
