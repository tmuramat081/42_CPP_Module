#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

void successfulCaseTest1()
{
	// 役人クラスを実体化
	Bureaucrat b("Tom", 1);
	std::cout << GREEN << b << DEFAULT << std::endl;

	// 書類クラスを実体化
	AForm *f0 = new ShrubberyCreationForm("Castle_Anthrax");
	AForm *f1 = new RobotomyRequestForm("RoboCop");
	AForm *f2 = new PresidentialPardonForm("Arthur Dent");

	// 署名と履行：盆栽を要求
	b.signForm(*f0);
	b.executeForm(*f0);

	// 署名と履行：ロボット化
	b.signForm(*f1);
	b.executeForm(*f1);

	// 署名と履行：銀河系大統領の恩赦
	b.signForm(*f2);
	b.executeForm(*f2);

	delete f0;
	delete f1;
	delete f2;
}

void successfulCaseTest2()
{
	// 役人クラスを実体化
	Bureaucrat b("Tom", 150);
	std::cout << GREEN << b << DEFAULT << std::endl;

	// 書類クラスを実体化
	AForm *f0 = new ShrubberyCreationForm("Castle_Anthrax");
	AForm *f1 = new RobotomyRequestForm("RoboCop");
	AForm *f2 = new PresidentialPardonForm("Arthur_Dent)");

	// 署名失敗（等級が未達・正常系）
	b.signForm(*f0);
	// 履行失敗（未署名・正常系）
	b.executeForm(*f0);

	// 署名失敗（等級が未達・正常系）
	b.signForm(*f1);
	// 履行失敗（未署名・正常系）
	b.executeForm(*f1);

	// 署名失敗（等級が未達・正常系）
	b.signForm(*f2);
	// 履行失敗（未署名・正常系）
	b.executeForm(*f2);

	delete f0;
	delete f1;
	delete f2;
}

void failureCaseTest()
{
	// 役人クラスを実体化
	Bureaucrat b("Tom", 150);
	std::cout << GREEN << b << DEFAULT << std::endl;

	// 書類クラスを実体化
	AForm *f0 = new ShrubberyCreationForm("Castle_Anthrax");
	AForm *f1 = new RobotomyRequestForm("RoboCop");
	AForm *f2 = new PresidentialPardonForm("Arthur_Dent)");

	try
	{
		// 不正な履行（未署名・異常系）
		f0->execute(b);
	}
	catch (AForm::NotSignedException &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << DEFAULT << std::endl;
	}
	try
	{
		// 不正な履行（未署名・異常系）
		f1->execute(b);
	}
	catch (AForm::NotSignedException &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << DEFAULT << std::endl;
	}
	try
	{
		// 不正な履行（未署名・異常系）
		f2->execute(b);
	}
	catch (AForm::NotSignedException &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << DEFAULT << std::endl;
	}

	delete f0;
	delete f1;
	delete f2;
}

int main()
{
	successfulCaseTest1();
	successfulCaseTest2();
	failureCaseTest();

	return 0;
}
