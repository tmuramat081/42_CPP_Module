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

	this->_formRepository[0] = &Intern::generateShrubberyCreationForm;
	this->_formRepository[1] = &Intern::generateRobotomyRequestForm;
	this->_formRepository[2] = &Intern::generatePresidentialPardonForm;
	this->_formRepository[3] = NULL;
}

Intern::Intern(const Intern &other)
{
	for (int i = 0; i < 4; ++i)
	{
		this->_nameRepository[i] = other._nameRepository[i];
		this->_formRepository[i] = other._formRepository[i];
	}
	*this = other;
}

Intern::~Intern() {}

// Operators
Intern &Intern::operator=(const Intern &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; ++i)
		{
			this->_nameRepository[i] = rhs._nameRepository[i];
			this->_formRepository[i] = rhs._formRepository[i];
		}
	}
	return *this;
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_nameRepository[i] == form)
		{
			std::cout << "Create " << form << std::endl;
			return (this->*_formRepository[i])(target);
		}
	}
	std::cout << "Not exist form." << std::endl;
	return NULL;
}

AForm *Intern::generateShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::generateRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::generatePresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
