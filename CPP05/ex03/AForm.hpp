#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm
{
public:
	// Constructors
	AForm();
	AForm(const std::string &name, const int signableGrade, const int executableGrade);
	AForm(const AForm &other);

	// Destructor
	virtual ~AForm() = 0;

	// Operators
	AForm &operator=(const AForm &assign);

	// Member functions
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	// Getters / setters
	const std::string &getName() const;
	int getSignableGrade() const;
	int getExecutableGrade() const;
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

protected:
	// 書類名
	const std::string _name;
	// 署名の有無
	bool _isSigned;
	// 署名可能な等級
	const int _signableGrade;
	// 履行可能な等級
	const int _executableGrade;
};

#endif
