#include "Array.hpp"

int main ()
{
	int * a = new int();
	std::cout << a << std::endl;

	Array<int> a0;
	Array<int> a1(10);


	return 0;
}
