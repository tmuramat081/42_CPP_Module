#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);

		// Destructor
		~Bureaucrat();

		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);

	private:

};

#endif