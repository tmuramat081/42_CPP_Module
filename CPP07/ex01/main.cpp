#include "iter.hpp"
#include <string>
#include <iostream>

void intFunc(const int elem)
{
	std::cout << elem << std::endl;
}

void strFunc(const std::string elem)
{
	std::cout << elem << std::endl;
}

int main()
{
	int array0[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string array1[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

	iter(array0, 10, intFunc);
	iter(array1, 10, strFunc);

	return (0);
}
