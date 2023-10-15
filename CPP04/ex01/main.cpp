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

// 100個のアイデアをすべて出力
void putIdeas(const Brain *brain)
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << brain->getIdea(i) << std::endl;
	}
}

// ランダムにアイデアを出力
void putIdeaByRandom(const Brain *brain)
{
	srand(static_cast<unsigned int>(time(0)));
	int index = rand() % 100;

	std::cout << GREEN; std::cout << "Pick up a next idea: ";
	std::cout << brain->getIdea(index);
	std::cout << DEFAULT << std::endl;
}

// アイデアを100個保存
void setIdeas(Brain *brain, const std::string ideas[100])
{
	for (int index = 0; index < 100; index++)
	{
		brain->setIdea(index, ideas[index]);
	}
}

int main()
{
	const Animal* array[10];
	for (int i = 0; i < 10; ++i)
	{
		if (i < 5)
			array[i] = new Dog;
		else
			array[i] = new Cat;
	}
	for (int i = 0; i < 10; ++i)
	{
		delete array[i];
	}

	Cat *test = new Cat;
	Cat *copy = new Cat(*test);

	std::cout << test->getBrain() << std::endl;
	std::cout << copy->getBrain() << std::endl;

	// 動物クラスのインスタンスを生成
	const Dog *dog = new Dog();
	Cat *cat = new Cat();

	// コピーを生成
	const Cat *copy_cat = new Cat(*cat);

	// 猫の脳を取得
	Brain *cat_brain = cat->getBrain();
	Brain *copy_cat_brain = copy_cat->getBrain();

	// 猫の脳にアイデアを保存
	setIdeas(cat_brain, fantasticIdeas);

	// 猫の脳のアイデアをすべて出力
	putIdeas(cat_brain);

	// 猫の脳のアイデアをランダムに出力
	putIdeaByRandom(cat_brain);
	// コピー先の無影響確認
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
