#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
public:
	// Constructors
	Bureaucrat();
	Bureaucrat(const std::string &name, const int grade);
	Bureaucrat(const Bureaucrat &other);

	// Destructor
	~Bureaucrat();

	// Operators
	Bureaucrat &operator=(const Bureaucrat &rhs);

	// Member functions
	void incrementGrade();
	void decrementGrade();

	// Getters / setters
	const std::string &getName() const;
	int getGrade() const;

	class GradeTooHighException : public std::exception
	{
		std::string message;

	public:
		GradeTooHighException();
		virtual ~GradeTooHighException() _NOEXCEPT;

		const char *what() const _NOEXCEPT;
	};

	class GradeTooLowException : public std::exception
	{
		std::string message;

	public:
		GradeTooLowException();
		virtual ~GradeTooLowException() _NOEXCEPT;

		const char *what() const _NOEXCEPT;
	};

private:
	std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat bureaucrat);

#endif
