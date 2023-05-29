#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

void successfulCaseTest()
{
	// 役人クラスを実体化
	Bureaucrat b("Tom", 1);
	std::cout << GREEN << b << DEFAULT << std::endl;

	// 書類クラスを実体化
	AForm *f0 = new ShrubberyCreationForm("Shrubbery_Creation");
	AForm *f1 = new RobotomyRequestForm("Robotomy_Request");
	AForm *f2 = new PresidentialPardonForm("Presidential_Pardon");

	// 署名と履行
	b.signForm(*f0);
	b.executeForm(*f0);

	b.signForm(*f1);
	b.executeForm(*f1);

	b.signForm(*f2);
	b.executeForm(*f2);

}

int main()
{
	successfulCaseTest();

	return 0;
}
