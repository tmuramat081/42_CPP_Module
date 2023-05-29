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

	this->_formRepository[0] = new ShrubberyCreationForm();
	this->_formRepository[1] = new RobotomyRequestForm();
	this->_formRepository[2] = new PresidentialPardonForm();
	this->_formRepository[3] = NULL;
}

Intern::Intern(const Intern &other) {}

Intern::~Intern() {}

// Operators
Intern &Intern::operator=(const Intern &assign)
{
	return *this;
}

void Intern::makeForm(const std::string &form, const std::string &target)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_nameRepository[i] == form)
		{
			this->_formRepository[i]->execute(target);
		}
	}

}