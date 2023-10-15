#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class Intern
{
public:
	// Constructors
	Intern();
	Intern(const Intern &copy);

	// Destructor
	~Intern();

	Intern &operator=(const Intern &rhs);

	// Member functions
	AForm *makeForm(const std::string &form, const std::string &target);

private:
	std::string _nameRepository[4];
	typedef AForm *(Intern::*formPtr)(const std::string &target);
	formPtr _formRepository[4];

	AForm *generateShrubberyCreationForm(const std::string &target);
	AForm *generateRobotomyRequestForm(const std::string &target);
	AForm *generatePresidentialPardonForm(const std::string &target);
};

#endif
