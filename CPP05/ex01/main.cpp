#include "Bureaucrat.hpp"


void successfulCaseTest()
{
	Bureaucrat b("Tom", 50);
	std::cout << b << std::endl;

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
		std::cerr << "Caught exception: " << e.what() << std::endl;
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
		std::cerr << "Caught exception: " << e.what() << std::endl;
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
