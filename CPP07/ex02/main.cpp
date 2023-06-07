#include "Array.hpp"

int main ()
{
	// int
	Array<int> a0;
	Array<int> a1(10);
	for (int i = 0; i < 10; ++i)
	{
		a1[i] = i;
	}
	for (int i = 0; i < 10; ++i)
	{
		std::cout << a1[i] << std::endl;
	}

	return 0;
}
