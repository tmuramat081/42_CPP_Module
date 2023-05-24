#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Fire.hpp"
#include <string>

int main()
{
	// マテリア管理用のインスタンスを生成
	IMateriaSource *src = new MateriaSource();

	// 各マテリアをセット
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());
	src->learnMateria(new Ice());

	std::cout << *src << std::endl;

	// キャラクター生成
	ICharacter *c1 = new Character("Cloud");
	ICharacter *c2 = new Character("Aerith");
	ICharacter *c3 = new Character("Sephiroth");

	AMateria *tmp;

	// マテリア装備
	tmp = src->createMateria("ice");
	c1->equip(tmp);
	tmp = src->createMateria("cure");
	c1->equip(tmp);
	tmp = src->createMateria("ice");
	c1->equip(tmp);
	std::cout << *c1 << std::endl;

	// マテリア解除
	c1->unequip(2);
	std::cout << *c1 << std::endl;
	c1->unequip(4);

	// マテリア再装備
	tmp = src->createMateria("fire");
	c1->equip(tmp);
	std::cout << *c1 << std::endl;

	// マテリア使用
	c1->use(0, *c3);
	c1->use(1, *c2);
	c1->use(2, *c3);
	c1->use(3, *c3);

	// インスタンスを削除
	delete c1;
	delete c2;
	delete c3;
	delete src;

	return 0;
}

#ifdef LEAKS_CHECK

__attribute__((destructor))
void end(void)
{
	system("leaks -q a.out");
}

#endif
