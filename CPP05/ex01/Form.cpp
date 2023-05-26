#include "Form.hpp"

// Constructors
Form::Form()
{
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &assign)
{
	(void) assign;
	return *this;
}

