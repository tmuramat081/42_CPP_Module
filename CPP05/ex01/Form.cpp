#include "Form.hpp"

// Constructors
Form::Form() : _name("default"), _isSigned(false), _signableGrade(100), _executableGrade(100) {}

Form::Form(const std::string &name, const int signableGrade, const int executableGrade): _name(name), _isSigned(false), _signableGrade(signableGrade), _executableGrade(executableGrade)
{
	if (this->_signableGrade < 1 || this->_executableGrade < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (this->_executableGrade > 150 || this->_executableGrade > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _signableGrade(other._signableGrade), _executableGrade(other._executableGrade)
{
	if (this->_signableGrade < 1 || this->_executableGrade < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (this->_signableGrade > 150 || this->_executableGrade > 150)
	{
		throw Form::GradeTooLowException();
	}
}

// Destructor
Form::~Form() {}

// Operators
Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return *this;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_signableGrade)
	{
		this->_isSigned = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

const std::string &Form::getName() const
{
	return this->_name;
}

int Form::getSignableGrade() const
{
	return this->_signableGrade;
}

bool Form::isSigned() const
{
	return this->_isSigned;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Form::GradeTooHighException::what()const throw()
{
	return this->message.c_str();
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Form::GradeTooLowException::what()const throw()
{
	return this->message.c_str();
}

const std::string Form::GradeTooHighException::message = "Grade is too high";
const std::string Form::GradeTooLowException::message = "Grade is too low";

std::ostream &operator<<(std::ostream &os, const Form form)
{
	os << "Name: " << form.getName() << ", ";
	os << "Grade: " << form.getSignableGrade() << ", ";
	os << "Sign: " << (form.isSigned() ? "Yes" : "No");
	return os;
}
