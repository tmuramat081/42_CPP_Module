#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

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

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade){}

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

void Bureaucrat::signForm(AForm &form)
{
	if (form.isSigned() == true)
	{
		std::cout << RED << this->_name << " couldn't sign " << form.getName() << " because already signed." << DEFAULT << std::endl;
		return ;
	}
	else if (form.getSignableGrade() < this->_grade)
	{
		std::cout << RED << this->_name << " couldn't sign " << form.getName();
		std::cout << " because not enough grade." << DEFAULT << std::endl;
		return ;
	}
	std::cout << this->_name << " signed " << form.getName() << std::endl;
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &form)
{
	if (form.isSigned() == false)
	{
		std::cout << RED << this->_name << " couldn't execute " << form.getName() << " because not signed." << DEFAULT << std::endl;
		return ;
	}
	else if (form.getExecutableGrade() < this->_grade)
	{
		std::cout << RED <<this->_name << " couldn't execute " << form.getName() << " because not enough grade." << DEFAULT << std::endl;
		return ;
	}
	std::cout << this->getName() <<  " executed " << form.getName() << std::endl;
	form.execute(*this);
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
		this->_grade = rhs._grade;
	}
	return *this;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->message.c_str();
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->message.c_str();
}

const std::string Bureaucrat::GradeTooHighException::message = "Grade is too high";
const std::string Bureaucrat::GradeTooLowException::message = "Grade is too low";

std::ostream &operator<<(std::ostream &os, const Bureaucrat bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

