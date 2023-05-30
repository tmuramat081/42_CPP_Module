#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

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
	void signForm(Form &form);

	// Getters / setters
	const std::string &getName() const;
	int getGrade() const;

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
	// 名前
	const std::string _name;
	// 等級
	int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat bureaucrat);

#endif
