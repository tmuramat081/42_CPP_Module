#include "Bureaucrat.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

void successfulCaseTest()
{
	Bureaucrat b("Tom", 75);
	std::cout << GREEN << b << DEFAULT << std::endl;

	for (int i = 0; i < 74; i++)
	{
		b.incrementGrade();
	}
	std::cout << GREEN << b << DEFAULT << std::endl;

	for (int i = 0; i < 149; i++)
	{
		b.decrementGrade();
	}
	std::cout << GREEN << b << DEFAULT << std::endl;
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
		std::cerr << RED << "Caught exception: " << e.what() << DEFAULT << std::endl;
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
		std::cerr << RED << "Caught exception: " << e.what() << DEFAULT << std::endl;
	}
	catch (...)
	{
		std::cerr << "Caught unknown exception" << std::endl;
	}
}

void failureCaseTest3()
{
	try
	{
		Bureaucrat b("Tom", 1);
		std::cout << b << std::endl;
		b.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << DEFAULT << std::endl;
	}
	catch (...)
	{
		std::cerr << "Caught unknown exception" << std::endl;
	}
}

void failureCaseTest4()
{
	try
	{
		Bureaucrat b("Tom", 150);
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << DEFAULT << std::endl;
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
	failureCaseTest3();
	failureCaseTest4();

	return 0;
}
