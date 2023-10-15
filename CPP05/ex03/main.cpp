#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

void successfulCaseTest()
{
	Bureaucrat b("Tom", 1);
	Intern i;
	AForm *f0;
	AForm *f1;
	AForm *f2;
	AForm *f3;

	f0 = i.makeForm("shrubbery creation", "Castle");
	f1 = i.makeForm("robotomy request", "RoboCop");
	f2 = i.makeForm("presidential pardon", "Arthur_Dent");
	f3 = i.makeForm("not_exist", "undefined");

	b.signForm(*f0);
	b.executeForm(*f0);

	b.signForm(*f1);
	b.executeForm(*f1);

	b.signForm(*f2);
	b.executeForm(*f2);

	delete f0;
	delete f1;
	delete f2;
	delete f3;
}

int main()
{
	successfulCaseTest();

	return 0;
}

#ifdef LEAKS_CHECK
__attribute__((destructor))
void end()
{
	system("leaks -q a.out");
}
#endif

