#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// 動物クラスのインスタンスを生成
	const Animal *meta = new Animal();
	const Animal *c = new Cat();
	const Animal *d = new Dog();

	// 動物の種類を出力
	std::cout << "Type: " << meta->getType() << " " << std::endl;
	std::cout << "Type: " << c->getType() << " " << std::endl;
	std::cout << "Type: " << d->getType() << " " << std::endl;

	// 動物の鳴き声
	meta->makeSound();
	c->makeSound();
	d->makeSound();

	delete meta;
	delete c;
	delete d;

	// 仮想関数を用いない場合
	const WrongAnimal *wmeta = new WrongAnimal();
	const WrongAnimal *wi = new WrongCat();

	// インターフェースが機能しない
	wmeta->makeSound();
	wi->makeSound();

	delete wmeta;
	delete wi;

	return 0;
}
