#include "Bureaucrat.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

void successfulCaseTest()
{
	Bureaucrat b("Tom", 75);
	std::cout << GREEN;
	std::cout << b;
	std::cout << DEFAULT << std::endl;

	for (int i = 0; i < 50; i++)
	{
		b.incrementGrade();
	}
	std::cout << GREEN;
	std::cout << b;
	std::cout << DEFAULT << std::endl;

	for (int i = 0; i < 50; i++)
	{
		b.decrementGrade();
	}
	std::cout << GREEN;
	std::cout << b;
	std::cout << DEFAULT << std::endl;
}

void failureCaseTest1()
{
	try
	{
		Bureaucrat b("Tom", 0);
		std::cout << b << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED;
		std::cerr << "Caught exception: " << e.what();
		;
		std::cout << DEFAULT << std::endl;
	}
	catch (...)
	{
		std::cerr << "Caught unknown exception" << std::endl;
	}
}

void failureCaseTest2()
{
	try
	{
		Bureaucrat b("Tom", 151);
		std::cout << b << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED;
		std::cerr << "Caught exception: " << e.what();
		std::cout << DEFAULT << std::endl;
	}
	catch (...)
	{
		std::cerr << "Caught unknown exception" << std::endl;
	}
}

int main()
{
	successfulCaseTest();
	failureCaseTest1();
	failureCaseTest2();

	return 0;
}
