#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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

	// 書類1
	ShrubberyCreationForm f0("contract");
	// 書類2
	RobotomyRequestForm f1("contract");

	// 署名に成功する
	f0.beSigned(b);

	// 履行に成功する
	f0.execute(b);

	f1.beSigned(b);
	f1.execute(b);

}

int main()
{
	successfulCaseTest();

	return 0;
}
