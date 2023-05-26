#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : _name("default"), _grade(1) {}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name), _grade(grade)
{
	if (this->_grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (this->_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	this->_name = other._name;
	this->_grade = other._grade;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade()
{
	--this->_grade;
	if (this->_grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade()
{
	++this->_grade;
	if (this->_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
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
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_grade = rhs._grade;
	}
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : message("Too high") {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return this->message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : message("Too low") {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return this->message.c_str();
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

