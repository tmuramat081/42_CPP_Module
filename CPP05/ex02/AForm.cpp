#include "AForm.hpp"

// Constructors
AForm::AForm() : _name("default"), _isSigned(false), _signableGrade(100), _executableGrade(100) {}

AForm::AForm(const std::string &name, const int signableGrade, const int executableGrade): _name(name), _isSigned(false), _signableGrade(signableGrade), _executableGrade(executableGrade)
{
	if (this->_signableGrade < 1 || this->_executableGrade < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (this->_executableGrade > 150 || this->_executableGrade > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _signableGrade(other._signableGrade), _executableGrade(other._executableGrade)
{
	if (this->_signableGrade < 1 || this->_executableGrade < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (this->_signableGrade > 150 || this->_executableGrade > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

// Destructor
AForm::~AForm() {}

// Operators
AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return *this;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_signableGrade)
	{
		this->_isSigned = true;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

const std::string &AForm::getName() const
{
	return this->_name;
}

int AForm::getSignableGrade() const
{
	return this->_signableGrade;
}

int AForm::getExecutableGrade() const
{
	return this->_executableGrade;
}

bool AForm::isSigned() const
{
	return this->_isSigned;
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char *AForm::GradeTooHighException::what()const throw()
{
	return this->message.c_str();
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char *AForm::GradeTooLowException::what()const throw()
{
	return this->message.c_str();
}

const std::string AForm::GradeTooHighException::message = "Grade is too high";
const std::string AForm::GradeTooLowException::message = "Grade is too low";
