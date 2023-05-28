#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm
{
public:
	// Constructors
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);

	// Destructor
	virtual ~ShrubberyCreationForm();

	// Member functions
	virtual void execute(Bureaucrat const &executor) const;

private:
	static const std::string ASCII_TREE;
};

#endif
