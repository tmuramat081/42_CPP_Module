#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <string>

int main()
{
	// マテリア管理用のインスタンスを生成
	IMateriaSource *src = new MateriaSource();

	// 各マテリアをセット
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << *src << std::endl;

	// エアリス登場
	ICharacter *c1 = new Character("Aerith");

	AMateria *tmp;

	// マテリア装備
	tmp = src->createMateria("ice");
	c1->equip(tmp);
	std::cout << *c1 << std::endl;
	tmp = src->createMateria("cure");
	c1->equip(tmp);
	std::cout << *c1 << std::endl;

	// セフィロス登場
	ICharacter *c2 = new Character("Sephiroth");

	// マテリア使用
	c1->use(0, *c2);
	c1->use(1, *c2);

	// インスタンスを削除
	delete c1;
	delete c2;
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
