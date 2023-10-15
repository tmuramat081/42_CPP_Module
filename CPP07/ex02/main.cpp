#include "Array.hpp"

struct S
{
	int num;
	std::string str;
};

const std::string digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

// type:int
void success_test1()
{
	// Default constructor
	Array<int> a0;
	// Parameterized constructor
	Array<int> a1(10);
	for (int i = 0; i < 10; ++i)
	{
		a1[i] = i;
	}
	// Copy constructor
	Array<int> a_copy1(a1);
	// Assignment operator
	Array<int> a_copy2 = a_copy1;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << a1[i];
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << a_copy1[i];
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << a_copy2[i];
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

// type:string
void success_test2()
{
	// Default constructor
	Array<std::string> a0;
	// Parameterized constructor
	Array<std::string> a1(10);
	for (int i = 0; i < 10; ++i)
	{
		a1[i] = digits[i];
	}
	// Copy constructor
	Array<std::string> a_copy1(a1);
	// Assignment operator
	Array<std::string> a_copy2 = a_copy1;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << a1[i];
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << a_copy1[i];
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << a_copy2[i];
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

// type:struct
void success_test3()
{
	// Default constructor
	Array<S> a0;
	// Parameterized constructor
	Array<S> a1(10);
	for (int i = 0; i < 10; ++i)
	{
		a1[i].num = i + 1;
		a1[i].str = digits[i];
	}

	// Copy constructor
	Array<S> a_copy1(a1);
	// Assignment operator
	Array<S> a_copy2 = a_copy1;

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "{" << a1[i].num << " " << a1[i].str << "}";
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "{" << a_copy1[i].num << " " << a_copy1[i].str << "}";
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "{" << a_copy2[i].num << " " << a_copy2[i].str << "}";
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

void failure_test()
{
	Array<float> a0(10);
	try
	{
		a0[-1];
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		a0[10];
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	success_test1();
	success_test2();
	success_test3();
	failure_test();
	return 0;
}

#ifdef LEAKS_CHECK
__attribute__((destructor))
void end()
{
	system("leaks -q a.out");
}
#endif
