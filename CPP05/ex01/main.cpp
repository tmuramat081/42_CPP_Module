#include "Bureaucrat.hpp"
#include "Form.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

void successfulCaseTest()
{
	// 役人クラスを実体化
	Bureaucrat b("Tom", 50);
	std::cout << GREEN << b << DEFAULT << std::endl;

	// 書類クラスを実体化
	Form f0("Sales Contract", 100, 50);
	std::cout << BLUE << f0 << DEFAULT << std::endl;
	Form f1("Employment Contract", 10, 50);
	std::cout << BLUE << f1 << DEFAULT << std::endl;

	// 署名に成功する
	b.signForm(f0);
	std::cout << BLUE << f0 << DEFAULT << std::endl;

	// 署名に失敗する（署名済みの場合・正常系）
	b.signForm(f0);
	std::cout << BLUE << f1 << DEFAULT << std::endl;

	// 署名に失敗する（等級が未達の場合・正常系）
	b.signForm(f1);
	std::cout << BLUE << f1 << DEFAULT << std::endl;
}

void failureCaseTest1()
{
	// 書類クラスの不正な実体化（範囲外の等級）
	try
	{
		Form f("Invalid Form", 151, 100);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << DEFAULT << std::endl;
	}
}

void failureCaseTest2()
{
	// 書類クラスの不正な実体化（範囲外の等級）
	try
	{
		Form f("Invalid Form", 0, 100);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << DEFAULT << std::endl;
	}
}

void failureCaseTest3()
{
	// 役人クラスを実体化
	Bureaucrat b("Tom", 50);
	std::cout << GREEN << b << DEFAULT << std::endl;

	// 書類クラスを実体化
	Form f0("Invalid Contract", 10, 50);
	std::cout << BLUE << f0 << DEFAULT << std::endl;

	// 不正な署名（クラスを直接呼び出し、かつ等級が未達の場合・異常系）
	try
	{
		f0.beSigned(b);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << DEFAULT << std::endl;
	}
}

int main()
{
	successfulCaseTest();
	failureCaseTest1();
	failureCaseTest2();
	failureCaseTest3();
	return 0;
}
