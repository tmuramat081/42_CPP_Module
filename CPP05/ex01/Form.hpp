#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Form
{
	public:
		// Constructors
		Form();
		Form(const Form &copy);

		// Destructor
		~Form();

		// Operators
		Form & operator=(const Form &assign);

	private:
		const std::string _name;
		bool _is_signed;
		const int _required_grade;

};

#endif