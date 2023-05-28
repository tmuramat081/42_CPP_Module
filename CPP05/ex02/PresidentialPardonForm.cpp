#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 25, 5) {}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!AForm::isSigned())
	{
		return ;
	}
	else if (executor.getGrade() > AForm::getExecutableGrade())
	{
		return ;
	}
	std::cout << "\033[0;34m<< Listen up, <target>! The coolest guy in the universe – yeah, that\'s me, Zaphod Beeblebrox – is giving you a full, all-access pardon! You're free, baby! Go and paint the cosmos red! >>" << std::endl;
	std::cout << ASCII_PRESIDENT << "\033[0m" << std::endl;
}

const std::string PresidentialPardonForm::ASCII_PRESIDENT =
"  _____   _____\n"
" /     \\ /     \\\n"
"| 0   0 | 0   0 |\n"
"|   ∆   |   ∆   |\n"
"(_______)(_______)\n"
"     |||     \n"
"    / | \\ \n";
