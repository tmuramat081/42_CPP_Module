#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm
{
public:
	// Constructors
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);

	// Destructor
	virtual ~RobotomyRequestForm();

	// Member functions
	virtual void execute(Bureaucrat const &executor) const;

private:
	static const std::string ASCII_ROBOT;
};

#endif
