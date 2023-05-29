#include "Bureaucrat.hpp"
#include "Form.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

void successfulCaseTest()
{
	// 役人
	Bureaucrat b("Tom", 50);
	std::cout << GREEN << b << DEFAULT << std::endl;

	// 書類1
	Form f0("Sales Contract", 100, 50);
	std::cout << BLUE << f0 << DEFAULT << std::endl;

	// 書類2
	Form f1("Employment Contract", 10, 50);
	std::cout << BLUE << f1 << DEFAULT << std::endl;

	// 署名に成功する
	f0.beSigned(b);
	std::cout << BLUE << f0 << DEFAULT << std::endl;

	// 署名に失敗する
	try
	{
		f1.beSigned(b);
		std::cout << f1 << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << DEFAULT << std::endl;
	}

	b.signForm(f0);
}

int main()
{
	successfulCaseTest();

	return 0;
}
