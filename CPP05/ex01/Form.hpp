#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
public:
	// Constructors
	Form();
	Form(const std::string &name, const int signableGrade, const int executableGrade);
	Form(const Form &other);

	// Destructor
	~Form();

	// Operators
	Form &operator=(const Form &assign);

	// Member functions
	void beSigned(const Bureaucrat &bureaucrat);

	// Getters / setters
	const std::string &getName() const;
	int getSignableGrade() const;
	bool isSigned() const;

	class GradeTooHighException : public std::exception
	{
		static const std::string message;

	public:
		~GradeTooHighException() throw();
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		static const std::string message;

	public:
		~GradeTooLowException() throw();
		const char *what() const throw();
	};

private:
	// 書類名
	const std::string _name;
	// 署名の有無
	bool _isSigned;
	// 署名可能な等級
	const int _signableGrade;
	// 履行可能な等級
	const int _executableGrade;
};

std::ostream &operator<<(std::ostream &os, const Form form);

#endif
