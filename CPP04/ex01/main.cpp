#include <cstdlib>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

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

	std::cout << "Pick up a random idea: ";
	std::cout << brain->getIdea(index) << std::endl;
}

int main()
{
	const Animal *cat = new Cat();

	putIdeas(cat->getBrain());
	putIdeaByRandom(cat->getBrain());

	delete cat;

	return 0;
}

#ifdef LEAK_CHECK
__attribute__((destructor))
void end(void)
{
	system("leaks -q a.out");
}
#endif
