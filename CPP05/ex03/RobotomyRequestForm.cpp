#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45) {}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!AForm::isSigned())
	{
		throw AForm::NotSignedException();
	}
	else if (executor.getGrade() > AForm::getExecutableGrade())
	{
		throw AForm::GradeTooHighException();
	}

	std::cout << "\033[0;34m<< VRRRRRRRRRR...VRRRRRRRR...DUGGADUGGADUGGA... >>\033[0m" << std::endl;

	std::srand(std::time(0));
	bool isSuccess = (std::rand() % 2 == 0) ? true : false;
	if (isSuccess)
	{
		std::cout << "\033[0;34mSuccessfully robotomized the " << this->_name << "!" << std::endl;
		std::cout << ASCII_ROBOT << "\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[0;31mFailed to robotomize the " << this->_name << "!\033[0m" << std::endl;
	}
}

const std::string RobotomyRequestForm::ASCII_ROBOT =
"         __\n"
" _(\\    |@@|\n"
"(__/\\__ \\--/ __\n"
"   \\___|----|  |   __\n"
"       \\ }{ /\\ )_ / _\\\n"
"       /\\__/\\ \\__O (__\n"
"      (--/\\--)    \\__/\n"
"      _)(  )(_\n"
"     `---''---`\n";
