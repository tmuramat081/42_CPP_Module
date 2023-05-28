#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm
{
public:
	// Constructors
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);

	// Destructor
	virtual ~PresidentialPardonForm();

	// Member functions
	virtual void execute(Bureaucrat const &executor) const;

private:
	static const std::string ASCII_PRESIDENT;
};

#endif
