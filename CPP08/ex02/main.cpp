#include "MutantStack.hpp"
#include <list>

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

void successful_test1()
{
	std::cout << GREEN << "-- Mutant stack --" << std::endl << DEFAULT;
	MutantStack<int> mstack;

	// push
	mstack.push(5);
	mstack.push(17);

	// top
	std::cout << mstack.top() << std::endl;

	// pop
	mstack.pop();

	std::cout << mstack.size() << std::endl;

	// push
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// iterator
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void successful_test2()
{
	std::cout << GREEN << "-- List --" << std::endl << DEFAULT;
	std::list<int> lstack;

	lstack.push_back(5);
	lstack.push_back(17);

	std::cout << lstack.back() << std::endl;

	lstack.pop_back();

	std::cout << lstack.size() << std::endl;

	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	lstack.push_back(0);

	std::list<int>::iterator it = lstack.begin();
	std::list<int>::iterator ite = lstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}


int main()
{
	successful_test1();
	successful_test2();

	return 0;
}
