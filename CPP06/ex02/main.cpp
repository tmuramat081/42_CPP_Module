#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base *generate(void)
{
	std::srand(std::time(0));
	int i = std::rand() % 3;
	std::cout << "\033[0;31mGenerate ";
	switch (i)
	{
	case 0:
		std::cout << "A" << std::endl;
		return (new A);
	case 1:
		std::cout << "B" << std::endl;
		return (new B);
	case 2:
		std::cout << "C" << std::endl;
		return (new C);
	}
	return NULL;
}

void identify(Base *p)
{
	std::cout << "\033[0;32mActual type is ";
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
	else
		std::cout << "unknown";
	std::cout << "\033[0m" << std::endl;
}

void identify(Base &p)
{
	std::cout << "\033[0;32mActual type is ";
	try
	{
		try
		{
			A &a = dynamic_cast<A &>(p);
			std::cout << "A";
			(void)a;
		}
		catch (std::bad_cast &e){}
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout << "B";
			(void)b;
		}
		catch (std::bad_cast &e){}
		try
		{
			C &c = dynamic_cast<C &>(p);
			std::cout << "C";
			(void)c;
		}
		catch (std::bad_cast &e){}
	}
	catch(...)
	{
		std::cout << "unknown";
	}
	std::cout << "\033[0m" << std::endl;
}

int main()
{
	// 派生クラスのインスタンスを生成する
	Base *base = generate();
	// 生成したインスタンスの型を特定する（ポインタ型）
	identify(base);
	// 生成したインスタンスの型を特定する（参照型）
	identify(*base);
	return (0);
}
