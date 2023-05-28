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
	// 役人
	Bureaucrat b("Tom", 1);
	std::cout << GREEN << b << DEFAULT << std::endl;

	// 書類クラスを実体化
	ShrubberyCreationForm f0("contract");
	RobotomyRequestForm f1("contract");
	PresidentialPardonForm f2("contract");

	// 署名と履行
	f0.beSigned(b);
	f0.execute(b);

	f1.beSigned(b);
	f1.execute(b);

	f2.beSigned(b);
	f2.execute(b);

}

int main()
{
	successfulCaseTest();

	return 0;
}
