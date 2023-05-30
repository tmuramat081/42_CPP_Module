#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	this->_nameRepository[0] = "shrubbery creation";
	this->_nameRepository[1] = "robotomy request";
	this->_nameRepository[2] = "presidential pardon";
	this->_nameRepository[3] = "";
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern() {}

// Operators
Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return *this;
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
	this->_formRepository[0] = new ShrubberyCreationForm(target);
	this->_formRepository[1] = new RobotomyRequestForm(target);
	this->_formRepository[2] = new PresidentialPardonForm(target);
	this->_formRepository[3] = NULL;

	for (int i = 0; i < 4; ++i)
	{
		if (this->_nameRepository[i] == form)
		{
			std::cout << "Create " << form << std::endl;
			return this->_formRepository[i];
		}
	}
	std::cout << "Not exist form." << std::endl;
	return NULL;
}
