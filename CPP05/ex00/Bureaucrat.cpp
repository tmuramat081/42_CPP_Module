#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string &name, const int grade): _name(name), _grade(grade)
{
	if (_grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

// Destructor
Bureaucrat::~Bureaucrat()
{
}

// Getters / setters
const std::string &Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(){}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw(){}
Bureaucrat::GradeTooHighException char* what() const {}

Bureaucrat::GradeTooLowException::GradeTooLowException(){}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){}
Bureaucrat::GradeTooLowException char* what() const {}
