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
	Intern deNiro;
	AForm *f;

	f = deNiro.makeForm("robotomy request", "RoboCop");

	delete f;
}

int main()
{
	successfulCaseTest();

	return 0;
}
